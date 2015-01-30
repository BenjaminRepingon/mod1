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
	var defaultRadius = 0.5;
	var particleSystem = new BABYLON.ParticleSystem("particles", 100, scene/*, effect*/);
	particleSystem.particleTexture = new BABYLON.Texture("textures/flare.png", scene);
	particleSystem.minSize = 0.1;
	particleSystem.maxSize = 1.0;
	particleSystem.minLifeTime = 0.5;
	particleSystem.maxLifeTime = 5.0;
	particleSystem.minEmitPower = 0.5;
	particleSystem.maxEmitPower = 3.0;
	particleSystem.emitter = emitter0;
	particleSystem.emitRate = 10;
	particleSystem.blendMode = BABYLON.ParticleSystem.BLENDMODE_ONEONE;
	particleSystem.direction1 = new BABYLON.Vector3(-1, 1, -1);
	particleSystem.direction2 = new BABYLON.Vector3(1, 1, 1);
	particleSystem.color1 = new BABYLON.Color4(0, 0.5, 1, 1);
	particleSystem.color2 = new BABYLON.Color4(0, 0.2, 0.5, 1);
	particleSystem.gravity = new BABYLON.Vector3(0, -10.0, 0);
	particleSystem.start();

	particleSystem.updateFunction = function ( particles )
	{
		for ( var index = 0; index < particles.length; index++ )
		{
			var particle = particles[index];

			console.log( "pok" )

			if ( particle.position.y - defaultRadius <= ground.position.y )
				particle.direction.y = 0;
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
