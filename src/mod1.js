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
	// BABYLON.Effect.ShadersStore["myParticleFragmentShader"] =
	// "#ifdef GL_ES\n" +
	// "precision highp float;\n" +
	// "#endif\n" +

	// "varying vec2 vUV;\n" +                     // Provided by babylon.js
	// "varying vec4 vColor;\n" +                  // Provided by babylon.js

	// "uniform sampler2D diffuseSampler;\n" +     // Provided by babylon.js
	// "uniform float time;\n" +                   // This one is custom so we need to declare it to the effect

	// "void main(void) {\n" +
	// 	"vec2 position = vUV;\n" +

	// 	"float color = 0.0;\n" +
	// 	"vec2 center = vec2(0.5, 0.5);\n" +

	// 	"color = sin(distance(position, center) * 10.0+ time * vColor.g);\n" +

	// 	"vec4 baseColor = texture2D(diffuseSampler, vUV);\n" +

	// 	"gl_FragColor = baseColor * vColor * vec4( vec3(color, color, color), 1.0 );\n" +
	// "}\n" +
	// "";

	// // Effect
	// var effect = engine.createEffectForParticles("myParticle", ["time"]);

	// Particles
	var defaultRadius = 0.3;
	var defaultRestitution = 0.2;
	var particleSystem = new BABYLON.ParticleSystem("particles", 2000, scene/*, effect*/);
	particleSystem.particleTexture = new BABYLON.Texture("textures/flare.png", scene);
	particleSystem.minSize = 1.0;
	particleSystem.maxSize = 1.0;
	particleSystem.minLifeTime = 5.0;
	particleSystem.maxLifeTime = 5.0;
	particleSystem.minEmitPower = 3.0;
	particleSystem.maxEmitPower = 3.0;
	particleSystem.emitter = emitter0;
	particleSystem.emitRate = 100;
	particleSystem.blendMode = BABYLON.ParticleSystem.BLENDMODE_ONEONE;
	particleSystem.direction1 = new BABYLON.Vector3(-0.1, -0.1, -0.1);
	particleSystem.direction2 = new BABYLON.Vector3(0.1, -0.1, 0.1);
	particleSystem.color1 = new BABYLON.Color4(0, 0.5, 1, 1);
	particleSystem.color2 = new BABYLON.Color4(0, 0.2, 0.5, 1);
	// particleSystem.gravity = new BABYLON.Vector3(0, -10.0, 0);
	particleSystem.start();

	particleSystem.updateFunction = function ( particles )
	{
		for ( var i = 0; i < particles.length; i++ )
		{
			// Update pos
			var particle = particles[i];
			particle.direction.y -= 0.005; // gravity
			particle.position = particle.position.add( particle.direction );
		}

		for ( var i = 0; i < particles.length; i++ )
		{
			var particle = particles[i];

			if ( particle.position.y - defaultRadius <= map.ground.position.y )
			{
				// particle.direction = BABYLON.Vector3( -0.5, -0.5, -0.5 );//particle.direction.multiply( BABYLON.Vector3( -0.5, -0.5, -0.5 ) );
				particle.position.y = map.ground.position.y + defaultRadius;

				particle.direction.x *= 0.975;
				particle.direction.y = 0;
				particle.direction.z *= 0.975;
			}
			for ( var j = i + 1; j < particles.length; j++ )
			{
				var particle2 = particles[j];

				if ( particle2.position.y - defaultRadius <= map.ground.position.y )
					particle2.direction.y = 0;

				var distVec = particle2.position.subtract( particle.position );
				var dist = distVec.length();

				if ( dist <= defaultRadius + defaultRadius )
				{
					var coeff = defaultRadius / dist;

					particle.position.x += particle.direction.x / -coeff;
					particle.position.y += particle.direction.y / -coeff;
					particle.position.z += particle.direction.z / -coeff;

					particle2.position.x += -particle.direction.x / -coeff;
					particle2.position.y += -particle.direction.y / -coeff;
					particle2.position.z += -particle.direction.z / -coeff;

					var tmp1 = particle.direction.length();
					var tmp2 = particle2.direction.length();
					var tmp3 = tmp2 / 2 + tmp1 / 2;

					particle.direction.subtractInPlace( distVec );
					particle.direction.normalize();
					particle.direction = particle.direction.multiplyByFloats( tmp3, tmp3, tmp3 );

					particle2.direction.addInPlace( distVec );
					particle2.direction.normalize();
					particle2.direction = particle2.direction.multiplyByFloats( tmp3, tmp3, tmp3 );
				}
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
