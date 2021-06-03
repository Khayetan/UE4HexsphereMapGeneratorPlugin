# UE4HexsphereMapGeneratorPlugin
An Unreal Engine 4 plugin that adds a hexagon sphere generator. 
This generator used to be a part of a bigger 4X game project I was working on in 2019 that I have since abandoned.

**Features:**
* Mesh generation. Each hex is created out of 12 triangles, this allows the mesh to be distorted in a way that makes the terrain more irregular.
* Hex connections. Makes it possible to navigate the map using a pathfinding algorithm like A*.
* Tri-planar material with a texture atlas. It's very easy to apply tiling textures, without any visible seams between hexes.
* Usable in Blueprint.

**How to use:**
* Instantiate a **HexsphereMapGenerator** and call *GenerateHexsphereData* with the desired settings.
* Create a **HexsphereMapComponent** then set it's **HexsphereMapDataSource** to the object returned by **GenerateHexsphereData**, then call *CreateHexsphereMapMesh* on the component.
* Apply a material to **HexsphereMapComponent**.

![Screenshot 2021-06-03 230738](https://user-images.githubusercontent.com/11838635/120712893-81c78180-c4c1-11eb-887c-155b848be865.png)

![Screenshot 2021-06-03 230807](https://user-images.githubusercontent.com/11838635/120712995-a02d7d00-c4c1-11eb-93cc-f2fae32fb7fd.png)

