window.onload = function(){
	var width = window.innerWidth;
	var height = window.innerHeight;
	var canvas = document.getElementById('canvas');

	canvas.setAttribute('width', width);
	canvas.setAttribute('height', height);

	var renderer = new THREE.WebGLRenderer({canvas: canvas});
	renderer.setClearColor('black');

	const scene = new THREE.Scene();

	var camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 5000);
	camera.position.set(0, 0, 1000);

	var light = new THREE.AmbientLight('white');
	scene.add(light);


	const geometry = new THREE.CylinderGeometry(200, 200, 250, 33, 30, 8, 8, 8);
	const material = new THREE.MeshBasicMaterial({color: 'blue', wireframe: true});

	// for(var i = 0; i < geometry.faces.length; i++){
	// 	geometry.faces[i].color.setRGB(Math.random(), Math.random(), Math.random());
	// }

	const mesh = new THREE.Mesh(geometry, material);
	scene.add(mesh);

	var gui = new dat.GUI();

	var ball = {
		rotationY: 0,
		scaleZ: 0,
		scaleY: 0,
		scaleX: 0
	};

	gui.add(ball, 'rotationY').min(-0.2).max(0.2).step(0.0001);
	gui.add(ball, 'scaleZ').min(100).max(500).step(0.0001);
	gui.add(ball, 'scaleY').min(80).max(500).step(0.0001);
	gui.add(ball, 'scaleX').min(80).max(500).step(0.0001);
	function loop(){
		mesh.rotation.y += ball.rotationY;
		mesh.scale.z += ball.scaleZ;
		mesh.scale.y += ball.scaleY;
		mesh.scale.x += ball.scaleX;
		mesh.scale.y <= 500;
		mesh.scale.x <= 500;
		mesh.scale.z <= 500;
		mesh.scale.y = mesh.scale.x;


		renderer.render(scene, camera);
		requestAnimationFrame(function(){loop();});
	}

	loop();
}