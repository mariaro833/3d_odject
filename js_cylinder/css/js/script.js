window.onload = function(){
	var width = window.innerWidth;
	var height = window.innerHeight;
	var canvas = document.getElementById('canvas');

	canvas.setAttribute('width', width);
	canvas.setAttribute('height', height);

	var ball = {
		rotationY: 0,
		// positionX: 0
		diameterC1: 150
	};

	var gui = new dat.GUI();
	gui.add(ball, 'diameterC1').min(80).max(500).step(10);
	gui.add(ball, 'rotationY').min(-0.2).max(0.2).step(0.0001);
	// gui.add(ball, 'positionX').min(-0.2).max(width / 2).step(0.1);

	var renderer = new THREE.WebGLRenderer({canvas: canvas});
	renderer.setClearColor('black');

	var scene = new THREE.Scene();

	var camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 5000);
	camera.position.set(0, 0, 1000);

	var light = new THREE.AmbientLight('white');
	scene.add(light);

	let diameterC1;
	let diameterC12;
	let hight;
	// widthC1 = widthC12 = 200;
	diameterC1 = diameterC12 = ball.diameterC1;

	hight = 200;
	var geometry = new THREE.CylinderGeometry(diameterC1, diameterC12, hight, 20, 8);
	var material = new THREE.MeshBasicMaterial({color: 'blue', wireframe: true});

	var mesh = new THREE.Mesh(geometry, material);
	scene.add(mesh);

	function loop(){
		// mesh.position.x += ball.positionX;
		mesh.rotation.y += ball.rotationY;
		// widthC1 += ball.widthC1;

		renderer.render(scene, camera);
		requestAnimationFrame(function(){loop();});
	}

	loop();
}