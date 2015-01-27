MOD1.scene = function( scene )
{
	// This creates and positions a free camera (non-mesh)
	var camera = new BABYLON.FreeCamera("camera1", new BABYLON.Vector3(0, 5, -10), scene);

	// This targets the camera to scene origin
	camera.setTarget(BABYLON.Vector3.Zero());

	// This attaches the camera to the canvas
	camera.attachControl(canvas, true);

	// This creates a light, aiming 0,1,0 - to the sky (non-mesh)
	var light = new BABYLON.HemisphericLight("light1", new BABYLON.Vector3(0, 1, 0), scene);
	var light0 = new BABYLON.PointLight("Omni0", new BABYLON.Vector3(-1, 1, -1), scene);
	light0.diffuse = new BABYLON.Color3(1, 0, 0);
	light0.specular = new BABYLON.Color3(1, 1, 1);

	// Default intensity is 1. Let's dim the light a small amount
	light.intensity = 0.7;

	// Our built-in 'sphere' shape. Params: name, subdivs, size, scene
	var sphere = BABYLON.Mesh.CreateSphere("sphere1", 16, 2, scene);

	// Move the sphere upward 1/2 its height
	sphere.position.y = 1;

	// Our built-in 'ground' shape. Params: name, width, depth, subdivs, scene
	var ground = BABYLON.Mesh.CreateGround("ground1", 6, 6, 2, scene);
}
