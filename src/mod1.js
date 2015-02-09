MOD1.scene = function( scene )
{
	var camera = new BABYLON.FreeCamera("camera1", new BABYLON.Vector3(50, 30, -70), scene);
	camera.setTarget(BABYLON.Vector3.Zero());
	camera.attachControl(canvas, true);

	var light = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 1, 0), scene);
	light.intensity = 0.7;
	// var light0 = new BABYLON.PointLight("Omni0", new BABYLON.Vector3(-1, 1, -1), scene);
	// light0.diffuse = new BABYLON.Color3(1, 0, 0);
	// light0.specular = new BABYLON.Color3(1, 1, 1);

	var map = new MOD1.Map(100, 100, scene, 2);
	map.ground.receiveShadows = true;

	var mat = new BABYLON.StandardMaterial("mat", scene);
	mat.diffuseColor = BABYLON.Color3.White();
	mat.wireframe = true;

	map.ground.material = mat;

	// Emitters
	var emitter0 = BABYLON.Mesh.CreateBox("emitter0", 0.1, scene);
	emitter0.position.y = 10;
	emitter0.position.x = 0;
	emitter0.position.z = 0;
	emitter0.isVisible = false;


	// Custom shader for particles
	BABYLON.Effect.ShadersStore["myParticleFragmentShader"] =
	"#ifdef GL_ES\n" +
	"precision highp float;\n" +
	"#endif\n" +

	"varying vec2 vUV;\n" +                     // Provided by babylon.js
	"varying vec4 vColor;\n" +                  // Provided by babylon.js

	"uniform sampler2D diffuseSampler;\n" +     // Provided by babylon.js
	"uniform float time;\n" +                   // This one is custom so we need to declare it to the effect

	"void main(void) \n" +
	"{\n" +
		"gl_FragColor = vColor;\n" +
	"}\n" +
	"";

	// // Effect
	var effect = engine.createEffectForParticles("myParticle"/*, ["time"]*/);

	// Particles
	var particleSystem = new BABYLON.ParticleSystem("particles", 500, scene/*, effect*/);
	particleSystem.particleTexture = new BABYLON.Texture("textures/flare.png", scene);
	particleSystem.minSize = 3.0;
	particleSystem.maxSize = 3.0;
	particleSystem.minLifeTime = 5.0;
	particleSystem.maxLifeTime = 5.0;
	particleSystem.minEmitPower = 3.0;
	particleSystem.maxEmitPower = 3.0;
	particleSystem.emitter = emitter0;
	particleSystem.emitRate = 100;
	particleSystem.blendMode = BABYLON.ParticleSystem.BLENDMODE_ONEONE;
	particleSystem.direction1 = new BABYLON.Vector3(-0.1, 0, -0.1);
	particleSystem.direction2 = new BABYLON.Vector3(0.1, 0, 0.1);
	particleSystem.color1 = new BABYLON.Color4(0, 0.5, 1, 1);
	particleSystem.color2 = new BABYLON.Color4(0, 0.2, 0.5, 1);
	// particleSystem.gravity = new BABYLON.Vector3(0, -10.0, 0);
	particleSystem.start();

	var iterations = 1;
	var defaultRadius = 1;
	var defaultMass = 10;
	var defaultWallMass = 100;
	var gravity = new BABYLON.Vector3( 0, -50, 0 );

	particleSystem.updateFunction = function ( particles )
	{
		// dt = scene.getEngine().getDeltaTime();
		fps = scene.getEngine().getFps();
		dt = 1 / fps;
		// console.log( "Frame per second: " + fps );
		// console.log( "Delta time: " + dt );
		// if ( fps < 60 )
		// {
		// 	console.log( "Collisions skiped" );
		// 	return ;
		// }
		contacts = [];

		// Generate new collision info
		for ( var i = 0; i < particles.length; i++ )
		{
			A = particles[i];

			if ( A.position.y - defaultRadius <= 0 )
			{
				B = {
					direction: new BABYLON.Vector3( 0, -A.direction.y, 0 ),
					position: new BABYLON.Vector3( A.position.x, 0, A.position.z )
				};

				normal = new BABYLON.Vector3( 0, -1, 0 );
				// normal = A.position.subtract( B.position );

				// normal.normalize();

				contacts.push ( {
						A: A,
						AMass: defaultMass,
						B: B,
						BMass: defaultWallMass,
						penetration: -( A.position.y - defaultRadius ),
						normal: normal,
					} );
			}

			wall = 50;
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
			if ( A.position.x - defaultRadius >= wall )
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
		// console.log( contacts.length + " collisions detected !" );

		// Integrate forces
		// for ( i = 0; i < particles.length; i++ )
		// 	particles[i].direction.addInPlace( gravity.multiplyByFloats( dt / 2.0, dt / 2.0, dt / 2.0 ) );
		// Integrate forces
		// for ( i = 0; i < particles.length; i++ )
		// {

		// }

		// Solve collisions
		for ( j = 0; j < iterations; j++ )
			for ( i = 0; i < contacts.length; i++ )
				applyImpulse( contacts[i] );

		// Integrate direction
		for ( i = 0; i < particles.length; i++ )
		{
			particles[i].position.addInPlace( particles[i].direction.multiplyByFloats( dt, dt, dt ) );
			particles[i].direction.addInPlace( gravity.multiplyByFloats( dt / 2.0, dt / 2.0, dt / 2.0 ) );
		}

		// Correct positions
		for ( i = 0; i < contacts.length; i++ )
			positionalCorrection( contacts[i] );
		// Correct positions
		for ( i = 0; i < particles.length; i++ )
			particles[i].direction = particles[i].direction.multiplyByFloats( 0.975, 0.975, 0.975 );
	}

	var positionalCorrection = function( contact )
	{
		A = contact.A;
		B = contact.B;

		k_slop = 0.0; // Penetration allowance
		percent = 0.5; // Penetration percentage to correct
		correction = ( Math.max( contact.penetration - k_slop, 0.0 ) / ( 1 / contact.AMass + 1 / contact.BMass ) ) * percent;
		correction = contact.normal.multiplyByFloats( correction, correction, correction );
		A.position.subtractInPlace( correction.multiplyByFloats( 1 / contact.AMass, 1 / contact.AMass, 1 / contact.AMass ) );
		B.position.addInPlace( correction.multiplyByFloats( 1 / contact.BMass, 1 / contact.BMass, 1 / contact.BMass ) );
	}

	var applyImpulse = function( contact )
	{
		A = contact.A;
		B = contact.B;
		// get the mtd
		// minimum translation distance to push balls apart after intersecting
		// tmp = contact.penetration / contact.distance;
		// mtd = contact.normal.multiplyByFloats( tmp, tmp, tmp );

		// resolve intersection --
		// inverse mass quantities
		im1 = 1 / contact.AMass;
		im2 = 1 / contact.BMass;

		// push-pull them apart based off their mass
		// tmp1 = im1 / ( im1 + im2 );
		// A.position.addInPlace( mtd.multiplyByFloats( tmp1, tmp1, tmp1 ) );
		// if ( B != 0 )
		// {
		// 	tmp2 = im2 / ( im1 + im2 );
		// 	B.position.subtractInPlace( mtd.multiplyByFloats( tmp2, tmp2, tmp2 ) );
		// }

		// impact speed
		v = A.direction.subtract( B.direction );
		vn = BABYLON.Vector3.Dot( v, contact.normal );

		// console.log( vn );

		// sphere intersecting but moving away from each other already
		// if ( vn > 0.0 )
		// 	return ;

		// collision impulse
		// console.log( contact.normal );

		// contact.normal = new BABYLON.Vector3( 0, -1, 0 );

		reduction = -0.4;
		i_ = ( -( 1.0 + reduction ) * vn ) / ( im1 + im2 );
		impulse = contact.normal.multiplyByFloats( i_, i_, i_ );

		// console.log( impulse );

		A.direction.addInPlace( impulse.multiplyByFloats( im1, im1, im1 ) );
		B.direction.subtractInPlace( impulse.multiplyByFloats( im2, im2, im2 ) );
	}

	// particleSystem.updateFunction = function ( particles )
	// {
	// 	// for ( var i = 0; i < particles.length; i++ )
	// 	// {
	// 	// 	// Update pos
	// 	// 	var particle = particles[i];
	// 	// }

	// 	for ( var i = 0; i < particles.length; i++ )
	// 	{
	// 		var particle = particles[i];

	// 		particle.direction.y -= 0.05; // gravity

	// 		if ( particle.sleep )
	// 			continue ;

	// 		// ground collision
	// 		if ( particle.position.y - defaultRadius <= map.ground.position.y )
	// 		{
	// 			// particle.direction = BABYLON.Vector3( -0.5, -0.5, -0.5 );//particle.direction.multiply( BABYLON.Vector3( -0.5, -0.5, -0.5 ) );
	// 			particle.position.y = map.ground.position.y + defaultRadius;

	// 			particle.direction.x *= 0.975;
	// 			particle.direction.y = 0;
	// 			particle.direction.z *= 0.975;
	// 		}

	// 		// Wall
	// 		var test = 8;
	// 		if ( particle.position.x - defaultRadius >= test )
	// 		{
	// 			particle.position.x = test + defaultRadius;
	// 			particle.direction.x = -particle.direction.x * 0.975;
	// 		}
	// 		if ( particle.position.x - defaultRadius <= -test )
	// 		{
	// 			particle.position.x = -test + defaultRadius;
	// 			particle.direction.x = -particle.direction.x * 0.975;
	// 		}
	// 		if ( particle.position.z - defaultRadius >= test )
	// 		{
	// 			particle.position.z = test + defaultRadius;
	// 			particle.direction.z = -particle.direction.z * 0.975;
	// 		}
	// 		if ( particle.position.z - defaultRadius <= -test )
	// 		{
	// 			particle.position.z = -test + defaultRadius;
	// 			particle.direction.z = -particle.direction.z * 0.975;
	// 		}

	// 		// 	 particle.position.z - defaultRadius >= test ||
	// 		// 	 particle.position.z - defaultRadius <= -test )
	// 		// {
	// 		// 	particle.position =
	// 		// 	particle.direction = particle.direction.multiplyByFloats( -0.975, -0.975, -0.975 );
	// 		// 	// particle.position = particle.direction.multiplyByFloats( -0.975, -0.975, -0.975 );
	// 		// }
	// 		for ( var j = 0; j < particles.length; j++ )
	// 		{
	// 			// don't check same
	// 			if ( i == j )
	// 				continue ;
	// 			var particle2 = particles[j];

	// 			var distVec = particle2.position.subtract( particle.position );
	// 			var dist = distVec.length();

	// 			if ( dist <= defaultRadius + defaultRadius )
	// 			{
	// 				// get the mtd
	// 				var delta = particle.position.subtract( particle2.position );
	// 				var d = delta.length();
	// 				// minimum translation distance to push balls apart after intersecting
	// 				var tmp = ( ( defaultRadius + defaultRadius ) -d ) / d;
	// 				var mtd = delta.multiplyByFloats( tmp, tmp, tmp );

	// 				// resolve intersection --
	// 				// inverse mass quantities
	// 				var mass = 10;
	// 				var im1 = 1 / 10;
	// 				var im2 = 1 / 10;

	// 				// push-pull them apart based off their mass
	// 				var tmp1 = im1 / ( im1 + im2 );
	// 				particle.position.addInPlace( mtd.multiplyByFloats( tmp1, tmp1, tmp1 ) );
	// 				var tmp2 = im2 / ( im1 + im2 );
	// 				particle2.position.subtractInPlace( mtd.multiplyByFloats( tmp2, tmp2, tmp2 ) );

	// 				// impact speed
	// 				var v = particle.direction.subtract( particle2.direction );
	// 				var vn = BABYLON.Vector3.Dot( v, mtd.normalize() );

	// 				// sphere intersecting but moving away from each other already
	// 				if ( vn > 0.0 )
	// 					continue ;

	// 				// collision impulse
	// 				var reduction = 0.2;
	// 				var i_ = ( -( 1.0 + reduction ) * vn ) / ( im1 + im2 );
	// 				var impulse = mtd.normalize().multiplyByFloats( i_, i_, i_ );

	// 				// change in momentum
	// 				if ( ! particle2.sleep )
	// 					particle.direction.addInPlace( impulse.multiplyByFloats( im1, im1, im1 ) );
	// 				if ( ! particle.sleep )
	// 					particle2.direction.subtractInPlace( impulse.multiplyByFloats( im2, im2, im2 ) );

	// 				// is sleep ?
	// 				if ( particle2.direction.x < precision && particle2.direction.x > -precision &&
	// 					 particle2.direction.y < precision && particle2.direction.y > -precision &&
	// 					 particle2.direction.z < precision && particle2.direction.z > -precision )
	// 				{
	// 					particle2.sleep = true;
	// 					particle2.direction = BABYLON.Vector3.Zero();
	// 					particle2.color = new BABYLON.Color4( 0.5, 0, 0, 1 );
	// 				}
	// 				else
	// 				{
	// 					particle2.sleep = false;
	// 					particle2.color = new BABYLON.Color4( 0, 0.35, 0.75, 1 );
	// 				}
	// 			}
	// 		}

	// 		// move
	// 		particle.position = particle.position.add( particle.direction );

	// 		// is sleep ?
	// 		if ( particle.direction.x < precision && particle.direction.x > -precision &&
	// 			 particle.direction.y < precision && particle.direction.y > -precision &&
	// 			 particle.direction.z < precision && particle.direction.z > -precision )
	// 		{
	// 			particle.sleep = true;
	// 			particle.direction = BABYLON.Vector3.Zero();
	// 			particle.color = new BABYLON.Color4( 0.5, 0, 0, 1 );
	// 		}
	// 		else
	// 		{
	// 			particle.sleep = false;
	// 			particle.color = new BABYLON.Color4( 0, 0.35, 0.75, 1 );
	// 		}
	// 	}
	// };

	// var time = 0;
	// var order = 0.1;

	// scene.registerBeforeRender(function () {
	// 	// Waiting for effect to be compiled
	// 	if (!effect) {
	// 		return;
	// 	}

	// 	effect.setFloat("time", time);

	// 	time += order;

	// 	if (time > 100 || time < 0) {
	// 		order *= -1;
	// 	}
	// });
}
