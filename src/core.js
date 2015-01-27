var MOD1;
(function (MOD1)
{
	MOD1.Core = function Core( scene )
	{
		this.scene = scene;
	}

	MOD1.Core.prototype.initScene = function()
	{
		MOD1.scene( this.scene );
	};
})(MOD1 || (MOD1 = {}));
