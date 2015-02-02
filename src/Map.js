var MOD1;
(function (MOD1)
{
	var debug = 0;
	MOD1.Map = function Map( width, height, scene, points )
	{
		this.indices = [];
		this.width = width;
		this.positions = [];
		this.normals = [];
		this.uvs = [];
		this.ground = new BABYLON.Mesh("Map", scene);
		this.altitude = [];

		this.basicGround( width, height, width , height , scene );

		var test = [[10, 10, 10], [20, 20, 10], [30, 10, 10], [35, 5, 10]];
		// var test = [[20, 85, 20], [35, -10, 35], [70, 40, 70]];
		// var test = [[50, 50, 50]];
		this.drawMontains(test, width);
		this.CreateArrayOfAltitude();

		/*
		** Set Vertices
		*/
		this.ground.setVerticesData(this.positions, BABYLON.VertexBuffer.PositionKind, true);
		this.ground.setVerticesData(this.normals, BABYLON.VertexBuffer.NormalKind, true);
		this.ground.setVerticesData(this.uvs, BABYLON.VertexBuffer.UVKind, true);
		this.ground.setIndices(this.indices);
	};

	MOD1.Map.prototype.getAltitude = function( x, y )
	{
		if ( Math.round(y) >= this.altitude.length || Math.round(y) < -50 )
			return 0;
		return ( this.altitude[Math.round( y )][Math.round( x )] + this.ground.position.y );
	};

	MOD1.Map.prototype.getCustomIndex = function( x, y )
	{
		return ( ( x * (this.width + 1) + y ) * 3 + 1 );
	};

	MOD1.Map.prototype.CreateArrayOfAltitude = function( )
	{
		for ( var i = 0; i < this.width ; i++ )
		{
			this.altitude[this.width - i - 50] = [];
			for ( var j = 0; j < this.width; j++ )
			{
				this.altitude[this.width - i - 50][j - 50] = this.positions[ this.getCustomIndex( i, j ) ];
			};
		};
	};

	MOD1.Map.prototype.drawMontains = function( points, width )
	{
		if ( points.length == 0 )
			return ;

		points.sort(function(a, b){ return a[1] - b[1] } );

		for (var i = points.length - 1; i >= 0; i--)
		{
			this.interpolVertex( points[i][0], points[i][2], points[i][1], width, 7, points );
		};
	};

	MOD1.Map.prototype.defineAltitude = function( x, y, points )
	{
		newAltitude = 0;
		nb_vertex = 0;

		for (var i = points.length - 1; i >= 0; i--)
		{
			tmpExp = Math.exp( - ( (points[i][0] - x) * (points[i][0] - x) ) / Math.abs( points[i][1] ) - ( (points[i][2] - y) * (points[i][2] - y) ) / Math.abs( points[i][1] ) );
			tmp = points[i][1] * tmpExp;
			if ( Math.abs( tmp ) > 0 )
			{
				newAltitude += tmp;
				nb_vertex ++;
			}
		};

		return (newAltitude / 2);
	}


	MOD1.Map.prototype.interpolVertex = function( x, y, altitude, width, smooth, points )
	{
		altitude = altitude < 0 ? altitude + 1 : altitude;

		for ( var i = 1; i <= Math.abs( altitude * smooth / 5 ); i++ )
		{
			for ( var j = 0; j <= 360; j+= 0.2 )
			{
				rad = (j * 3.14159) / 180;
				a = Math.ceil( x + i * Math.cos(rad) );
				b = Math.ceil( y + i * Math.sin(rad) );
				if ( a < width && a >= 0 && b < width && b >= 0)
				{
					index = this.getCustomIndex( a, b, width );
					newAltitude = this.defineAltitude( a, b, points );
					this.positions[ index ] = newAltitude;
				}

			};
		};
	};

	MOD1.Map.prototype.basicGround = function( width, height, w_subdivisions, h_subdivisions, scene)
	{
		var row, col;

		for (row = 0; row <= h_subdivisions; row++)
		{
			for (col = 0; col <= w_subdivisions; col++)
			{
				var position = new BABYLON.Vector3((col * width) / w_subdivisions - (width / 2.0), 0, ((h_subdivisions - row) * height) / h_subdivisions - (height / 2.0));
				var normal = new BABYLON.Vector3(0, 1.0, 0);

				this.positions.push(position.x, position.y, position.z);
				this.normals.push(normal.x, normal.y, normal.z);
				this.uvs.push(col / w_subdivisions, 1.0 - row / h_subdivisions);
			}
		}

		for (row = 0; row < h_subdivisions; row++)
		{
			for (col = 0; col < w_subdivisions; col++)
			{
				this.indices.push(col + 1 + (row + 1) * (w_subdivisions + 1));
				this.indices.push(col + 1 + row * (w_subdivisions + 1));
				this.indices.push(col + row * (w_subdivisions + 1));

				this.indices.push(col + (row + 1) * (w_subdivisions + 1));
				this.indices.push(col + 1 + (row + 1) * (w_subdivisions + 1));
				this.indices.push(col + row * (w_subdivisions + 1));
			}
		}
	};

})(MOD1 || (MOD1 = {}));
