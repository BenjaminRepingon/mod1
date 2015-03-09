MOD1.scene = function( scene )
{
	console.log(param_mod);
	console.log(param_map);
	var camera = new BABYLON.FreeCamera("camera1", new BABYLON.Vector3(50, 30, -70), scene);
	camera.setTarget(BABYLON.Vector3.Zero());
	camera.attachControl(canvas, true);

	// var light = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 0.5, 0.9), scene);
	// light.intensity = 0.7;
	// light.diffuse = new BABYLON.Color3(0.9, 0.9, 0.9);
	// light.specular = new BABYLON.Color3(0.7, 0.6, 0.5);

	var light = new BABYLON.DirectionalLight("dir01", new BABYLON.Vector3(-1, -2, -1), scene);
	light.position = new BABYLON.Vector3(20, 40, 20);
	light.intensity = 0.5;
	var light2 = new BABYLON.PointLight("Omni0", new BABYLON.Vector3(1, 10, 1), scene);
	light2.intensity = 0.5;
	light.diffuse = new BABYLON.Color3(0.4, 0.6, 0.4);
	light.specular = new BABYLON.Color3(0.4, 0.6, 0.4);

	var shadowGenerator = new BABYLON.ShadowGenerator(1024, light);

	var map = new MOD1.Map(100, 100, scene, 2);
	map.ground.receiveShadows = true;

	var mat = new BABYLON.StandardMaterial("mat", scene);
	mat.diffuseColor = new BABYLON.Color3( 0.8, 0.8, 0.8 );

	map.ground.material = mat;

	// Emitters
	var emitter0 = BABYLON.Mesh.CreateBox("emitter0", 0.1, scene);
	emitter0.position.x = 0;
	emitter0.position.z = 0;
	emitter0.isVisible = false;

	// Particles
	var particleSystem = new BABYLON.ParticleSystem("particles", 1000, scene);
	particleSystem.particleTexture = new BABYLON.Texture("textures/flare.png", scene);
	particleSystem.minSize = 7.5;
	particleSystem.maxSize = 7.5;
	particleSystem.minLifeTime = 5.0;
	particleSystem.maxLifeTime = 5.0;
	particleSystem.minEmitPower = 3.0;
	particleSystem.maxEmitPower = 3.0;

	// Wave
	if ( param_mod == "wave" )
	{
		particleSystem.minEmitBox = new BABYLON.Vector3(50, 0, 50);
		particleSystem.maxEmitBox = new BABYLON.Vector3(50, 1, -50);
		emitter0.position.y = 10;
		particleSystem.emitRate = 100;
	}
	else if ( param_mod == "water" )
	{
		particleSystem.minEmitBox = new BABYLON.Vector3(-48, 0, -48);
		particleSystem.maxEmitBox = new BABYLON.Vector3(48, 0, 48);
		emitter0.position.y = 5;
		particleSystem.emitRate = 25;
	}
	else if ( param_mod == "rain" )
	{
		particleSystem.minEmitBox = new BABYLON.Vector3(-48, 0, -48);
		particleSystem.maxEmitBox = new BABYLON.Vector3(48, 0, 48);
		emitter0.position.y = 100;
		particleSystem.emitRate = 25;
	}

	particleSystem.emitter = emitter0;

	// particleSystem.blendMode = BABYLON.ParticleSystem.BLENDMODE_ONEONE;
	particleSystem.direction1 = new BABYLON.Vector3(0, 1, 0);
	particleSystem.direction2 = new BABYLON.Vector3(0, 1, 0);
	particleSystem.color1 = new BABYLON.Color4(0, 0.7, 1, 1);
	particleSystem.color2 = new BABYLON.Color4(0, 0.5, 0.7, 1);
	// particleSystem.gravity = new BABYLON.Vector3(0, -10.0, 0);
	particleSystem.start();

	var iterations = 1;
	var defaultRadius = 2.5;
	var defaultMass = 10;
	var defaultWallMass = 100000;
	var gravity = new BABYLON.Vector3( 0, -100, 0 );
	var wall = 50 - defaultRadius - defaultRadius;

	var test = function( x, z )
	{
		return ( new BABYLON.Vector3( Math.round( x ), map.getAltitude( x, z ), Math.round( z ) ) );
	}

	function toRad( value )
	{
		/** Converts numeric degrees to radians */
		return ( value * Math.PI / 180 );
	}

	function toDeg( value )
	{
		/** Converts numeric radians to degrees */
		return ( value * 180 / Math.PI );
	}

	function checkTriangleCollide( A, B, C, Particle, contacts )
	{
		V = BABYLON.Vector3.Cross( B.subtract( A ), C.subtract( A ) );

		A = A.subtract( Particle.position );
		B = B.subtract( Particle.position );
		C = C.subtract( Particle.position );

		rr = defaultRadius * defaultRadius;

		d = BABYLON.Vector3.Dot( A, V );
		e = BABYLON.Vector3.Dot( V, V );
		sep1 = d * d > rr * e;

		if ( sep1 )
			return ;

		if ( true || ! separated )
		{
			N = V.normalize();
			distance = Math.abs( BABYLON.Vector3.Dot( A, N ) - defaultRadius );
			B = {
				direction: N.multiplyByFloats( distance, distance, distance ),
				position: BABYLON.Vector3.Zero()
			};
			contacts.push ( {
					A: Particle,
					AMass: defaultMass,
					B: B,
					BMass: defaultWallMass,
					penetration: distance,
					normal: N,
				} );
		}
	}

	var frame = 0;
	particleSystem.updateFunction = function ( particles )
	{
		fps = scene.getEngine().getFps();
		dt = 1 / 60;

		contacts = [];

		// Generate new collision info
		for ( var i = 0; i < particles.length; i++ )
		{
			A = particles[i];

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x, A.position.z - 1 );
			C_ = test( A.position.x + 1, A.position.z );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x + 1, A.position.z + 1 );
			C_ = test( A.position.x, A.position.z + 1 );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x + 1, A.position.z );
			C_ = test( A.position.x + 1, A.position.z + 1 );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x, A.position.z + 1 );
			C_ = test( A.position.x - 1, A.position.z );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x - 1, A.position.z );
			C_ = test( A.position.x - 1, A.position.z - 1 );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			A_ = test( A.position.x, A.position.z );
			B_ = test( A.position.x - 1, A.position.z - 1 );
			C_ = test( A.position.x, A.position.z - 1 );
			checkTriangleCollide( A_, B_, C_, A, contacts );

			if ( A.position.x + defaultRadius <= -wall )
			{
				B = {
					direction: new BABYLON.Vector3( -A.direction.x, 0, 0 ),
					position: new BABYLON.Vector3( -wall, A.position.y, A.position.z )
				};

				normal = new BABYLON.Vector3( -1, 0, 0 );

				normal.normalize();

				contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultWallMass,
						penetration: -( A.position.x + defaultRadius ) - wall,
						normal: normal,
					} );
			}
			if ( A.position.x - defaultRadius >= wall)
			{
				B = {
					direction: new BABYLON.Vector3( -A.direction.x, 0, 0 ),
					position: new BABYLON.Vector3( wall, A.position.y, A.position.z )
				};

				normal = new BABYLON.Vector3( 1, 0, 0 );

				normal.normalize();

				contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultWallMass,
						penetration: ( A.position.x - defaultRadius ) - wall,
						normal: normal,
					} );
			}
			if ( A.position.z + defaultRadius <= -wall )
			{
				B = {
					direction: new BABYLON.Vector3( 0, 0, -A.direction.z ),
					position: new BABYLON.Vector3( A.position.x, A.position.y, -wall )
				};

				normal = new BABYLON.Vector3( 0, 0, -1 );

				normal.normalize();

				contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultWallMass,
						penetration: -( A.position.z + defaultRadius ) - wall,
						normal: normal,
					} );
			}
			if ( A.position.z - defaultRadius >= wall )
			{
				B = {
					direction: new BABYLON.Vector3( 0, 0, -A.direction.z ),
					position: new BABYLON.Vector3( A.position.x, A.position.y, wall )
				};

				normal = new BABYLON.Vector3( 0, 0, 1 );

				normal.normalize();

				contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultWallMass,
						penetration: ( A.position.z - defaultRadius ) - wall,
						normal: normal,
					} );
			}

			for ( var j = i + 1; j < particles.length; j++ )
			{
				B = particles[j];

				if ( B.sleep )
					continue ;
				// Calculate translational vector, which is normal
				normal = B.position.subtract( A.position );

				dist_sqr = normal.lengthSquared();
				radius = defaultRadius + defaultRadius;

				// Not in contact
				if ( dist_sqr >= radius * radius )
					continue ;

				distance = Math.sqrt( dist_sqr );

				if ( distance == 0.0 )
				{
					contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultMass,
						penetration: defaultRadius,
						normal: new BABYLON.Vector3( 0, -1, 0 ),
					} );
				}
				else
				{
					tmpDist = 1 / distance;
					tmpNormal = normal.multiplyByFloats( tmpDist, tmpDist, tmpDist );
					contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultMass,
						penetration: radius - distance,
						normal: tmpNormal,
					} );
				}
			}
		}

		// Integrate forces
		for ( i = 0; i < particles.length; i++ )
			particles[i].direction.addInPlace( gravity.multiplyByFloats( dt / 2.0, dt / 2.0, dt / 2.0 ) );

		// Correct positions
		for ( i = 0; i < contacts.length; i++ )
		{
			applyImpulse( contacts[i] );
			positionalCorrection( contacts[i] );
		}

		// Integrate direction
		for ( i = 0; i < particles.length; i++ )
		{
			particles[i].position.addInPlace( particles[i].direction.multiplyByFloats( dt, dt, dt ) );
			particles[i].direction.addInPlace( gravity.multiplyByFloats( dt / 2.0, dt / 2.0, dt / 2.0 ) );
			particles[i].direction = particles[i].direction.multiplyByFloats( 0.975, 0.975, 0.975 );
		}
	}

	var positionalCorrection = function( contact )
	{
		A = contact.A;
		B = contact.B;

		k_slop = 0.0;
		percent = 0.2;
		correction = ( Math.max( contact.penetration - k_slop, 0.0 ) / ( 1 / contact.AMass + 1 / contact.BMass ) ) * percent;
		correction = contact.normal.multiplyByFloats( correction, correction, correction );
		A.position.subtractInPlace( correction.multiplyByFloats( 1 / contact.AMass, 1 / contact.AMass, 1 / contact.AMass ) );
		B.position.addInPlace( correction.multiplyByFloats( 1 / contact.BMass, 1 / contact.BMass, 1 / contact.BMass ) );
	}

	var applyImpulse = function( contact )
	{
		A = contact.A;
		B = contact.B;

		im1 = 1 / contact.AMass;
		im2 = 1 / contact.BMass;

		// impact speed
		v = A.direction.subtract( B.direction );
		vn = BABYLON.Vector3.Dot( v, contact.normal );

		reduction = -0.4;
		i_ = ( -( 1.0 + reduction ) * vn ) / ( im1 + im2 );
		impulse = contact.normal.multiplyByFloats( i_, i_, i_ );

		A.direction.addInPlace( impulse.multiplyByFloats( im1, im1, im1 ) );
		B.direction.subtractInPlace( impulse.multiplyByFloats( im2, im2, im2 ) );
	}
}
