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
	var defaultRadius = 0.35;
	var defaultRestitution = 0.2;
	var particleSystem = new BABYLON.ParticleSystem("particles", 1800, scene/*, effect*/);
	particleSystem.particleTexture = new BABYLON.Texture("textures/flare.png", scene);
	particleSystem.minSize = 1.0;
	particleSystem.maxSize = 1.0;
	particleSystem.minLifeTime = 5.0;
	particleSystem.maxLifeTime = 5.0;
	particleSystem.minEmitPower = 3.0;
	particleSystem.maxEmitPower = 3.0;
	particleSystem.emitter = emitter0;
	particleSystem.emitRate = 400;
	particleSystem.blendMode = BABYLON.ParticleSystem.BLENDMODE_ONEONE;
	particleSystem.direction1 = new BABYLON.Vector3(-0.1, -0.1, -0.1);
	particleSystem.direction2 = new BABYLON.Vector3(0.1, -0.1, 0.1);
	particleSystem.color1 = new BABYLON.Color4(0, 0.5, 1, 1);
	particleSystem.color2 = new BABYLON.Color4(0, 0.2, 0.5, 1);
	// particleSystem.gravity = new BABYLON.Vector3(0, -10.0, 0);
	particleSystem.start();

	var precision = 0.01;

	particleSystem.updateFunction = function ( particles )
	{
		// for ( var i = 0; i < particles.length; i++ )
		// {
		// 	// Update pos
		// 	var particle = particles[i];
		// }

		for ( var i = 0; i < particles.length; i++ )
		{
			var particle = particles[i];

			particle.direction.y -= 0.05; // gravity

			if ( particle.sleep )
				continue ;

			// ground collision
			inclination = new BABYLON.Vector3(0, 0, 0);
			groundAltitude = map.getAltitude( particle.position.x, particle.position.z );
			// groundAltitude = map.ground.position.y;
			if ( particle.position.y - defaultRadius <= groundAltitude )
			{
				// particle.direction = BABYLON.Vector3( -0.5, -0.5, -0.5 );//particle.direction.multiply( BABYLON.Vector3( -0.5, -0.5, -0.5 ) );
				particle.position.y = groundAltitude + defaultRadius;

				// groundAltitude;
				diffPoint = map.getAltitude( particle.position.x - 1, particle.position.z );

				if ( diffPoint < groundAltitude )
				{
					inclination = new BABYLON.Vector3( -1, diffPoint - groundAltitude, 0 );
					groundAltitude = diffPoint;
				}

				diffPoint = map.getAltitude( particle.position.x + 1, particle.position.z );

				if ( diffPoint < groundAltitude )
				{
					inclination = new BABYLON.Vector3( 1, diffPoint - groundAltitude, 0 );
					groundAltitude = diffPoint;
				}


				diffPoint = map.getAltitude( particle.position.x, particle.position.z - 1 );

				if ( diffPoint < groundAltitude )
				{
					inclination = new BABYLON.Vector3( 0 , diffPoint - groundAltitude, -1 );
					groundAltitude = diffPoint;
				}

				diffPoint = map.getAltitude( particle.position.x, particle.position.z + 1 );

				if ( diffPoint < groundAltitude )
				{
					inclination = new BABYLON.Vector3( 0 , diffPoint - groundAltitude, 1 );
					groundAltitude = diffPoint;
				}
				// tmp = map.getAltitude( particle.position.x - 1, particle.position.z );
				// if ( tmp < diffPoint )
				// {
				// 	slope = new BABYLON.Vector3( -1, particle.position.z , tmp );
				// 	diffPoint = tmp;
				// }
				// tmp = map.getAltitude( particle.position.x + 1, particle.position.z );
				// if ( tmp < diffPoint )
				// {
				// 	slope = new BABYLON.Vector3( 1, particle.position.z , tmp );
				// 	diffPoint = tmp;
				// }
				// diffPoint = diffPoint > tmp ? tmp : diffPoint;
				// tmp = map.getAltitude( particle.position.x, particle.position.z - 1 );
				// if ( tmp < diffPoint )
				// {
				// 	slope = new BABYLON.Vector3( particle.position.x, -1 , tmp );
				// 	diffPoint = tmp;
				// }
				// diffPoint = diffPoint > tmp ? tmp : diffPoint;
				// tmp = map.getAltitude( particle.position.x, particle.position.z + 1 );
				// if ( tmp < diffPoint )
				// {
				// 	slope = new BABYLON.Vector3( particle.position.x, 1 , tmp );
				// 	diffPoint = tmp;
				// }
				// diffPoint = diffPoint > tmp ? tmp : diffPoint;



				inclination.normalize();
				// inclination.multiplyByFloats( particle.direction.length() * 0.0000001, particle.direction.length() * 0.0000001, particle.direction.length() * 0.0000001 );

				particle.direction.x += inclination.x;
				// particle.direction.y += inclination.y;
				particle.direction.z += inclination.z;

				if ( particle.direction.y > 0.001 )
				{
					particle.direction.x *= 0.5;
					particle.direction.y *= 0.5;
					particle.direction.z *= 0.5;
				}

				particle.direction.x *= 0.975;
				particle.direction.y = 0;
				particle.direction.z *= 0.975;
				// particle.direction.addInPlace( diffPoint );
			}

			// Wall
			var test = 15;
			if ( particle.position.x - defaultRadius >= test )
			{
				particle.position.x = test + defaultRadius;
				particle.direction.x = -particle.direction.x * 0.975;
			}
			if ( particle.position.x - defaultRadius <= -test )
			{
				particle.position.x = -test + defaultRadius;
				particle.direction.x = -particle.direction.x * 0.975;
			}
			if ( particle.position.z - defaultRadius >= test )
			{
				particle.position.z = test + defaultRadius;
				particle.direction.z = -particle.direction.z * 0.975;
			}
			if ( particle.position.z - defaultRadius <= -test )
			{
				particle.position.z = -test + defaultRadius;
				particle.direction.z = -particle.direction.z * 0.975;
			}

			// 	 particle.position.z - defaultRadius >= test ||
			// 	 particle.position.z - defaultRadius <= -test )
			// {
			// 	particle.position =
			// 	particle.direction = particle.direction.multiplyByFloats( -0.975, -0.975, -0.975 );
			// 	// particle.position = particle.direction.multiplyByFloats( -0.975, -0.975, -0.975 );
			// }
			for ( var j = 0; j < particles.length; j++ )
			{
				// don't check same
				if ( i == j )
					continue ;
				var particle2 = particles[j];

				var distVec = particle2.position.subtract( particle.position );
				var dist = distVec.length();

				if ( dist <= defaultRadius + defaultRadius )
				{
					// get the mtd
					var delta = particle.position.subtract( particle2.position );
					var d = delta.length();
					// minimum translation distance to push balls apart after intersecting
					var tmp = ( ( defaultRadius + defaultRadius ) -d ) / d;
					var mtd = delta.multiplyByFloats( tmp, tmp, tmp );

					// resolve intersection --
					// inverse mass quantities
					var mass = 10;
					var im1 = 1 / 10;
					var im2 = 1 / 10;

					// push-pull them apart based off their mass
					var tmp1 = im1 / ( im1 + im2 );
					particle.position.addInPlace( mtd.multiplyByFloats( tmp1, tmp1, tmp1 ) );
					var tmp2 = im2 / ( im1 + im2 );
					particle2.position.subtractInPlace( mtd.multiplyByFloats( tmp2, tmp2, tmp2 ) );

					// impact speed
					var v = particle.direction.subtract( particle2.direction );
					var vn = BABYLON.Vector3.Dot( v, mtd.normalize() );

					// sphere intersecting but moving away from each other already
					if ( vn > 0.0 )
						continue ;

					// collision impulse
					var reduction = 0.5;
					var i_ = ( -( 1.0 + reduction ) * vn ) / ( im1 + im2 );
					var impulse = mtd.normalize().multiplyByFloats( i_, i_, i_ );

					// change in momentum
					if ( ! particle2.sleep )
						particle.direction.addInPlace( impulse.multiplyByFloats( im1, im1, im1 ) );
					if ( ! particle.sleep )
						particle2.direction.subtractInPlace( impulse.multiplyByFloats( im2, im2, im2 ) );

					// is sleep ?
					if ( particle2.direction.x < precision && particle2.direction.x > -precision &&
						 particle2.direction.y < precision && particle2.direction.y > -precision &&
						 particle2.direction.z < precision && particle2.direction.z > -precision )
					{
						particle2.sleep = true;
						particle2.direction = BABYLON.Vector3.Zero();
						particle2.color = new BABYLON.Color4( 0.5, 0, 0, 1 );
					}
					else
					{
						particle2.sleep = false;
						particle2.color = new BABYLON.Color4( 0, 0.35, 0.75, 1 );
					}
				}
			}

			// move
			particle.position = particle.position.add( particle.direction );

			// is sleep ?
			if ( particle.direction.x < precision && particle.direction.x > -precision &&
				 particle.direction.y < precision && particle.direction.y > -precision &&
				 particle.direction.z < precision && particle.direction.z > -precision )
			{
				particle.sleep = true;
				particle.direction = BABYLON.Vector3.Zero();
				particle.color = new BABYLON.Color4( 0.5, 0, 0, 1 );
			}
			else
			{
				particle.sleep = false;
				particle.color = new BABYLON.Color4( 0, 0.35, 0.75, 1 );
			}
		}
	};

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
