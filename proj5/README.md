# art
Another Ray Tracer


## How to use

|  Command           | Description  |
| :-----| :-------------|
| ```$ make``` | Compile |
| ```$ ./canvas.out <path_to_scene_file>.json``` | Run | 


## Usage

In order to describe a scene, specify the
`filename` where the image will be saved inside the `gallery` folder, as well as the objects, and the camera's width and height. If the paratemer osn't specified, the filename will be the same as the scene file. The default image extension is `.ppm`.

You can set the parameter `overwrite_file` to indicate whether the image should be overwrite when it alread exists in the `gallery` folder. In the scene below, if therer already exists a `final.ppm` file, the new image will be `final_1.ppm`.

```json
{
	"scene": {
        "camera":{
            "width": 200,
            "height": 100
        },
        "background":...
        },
        "filename":"final",
        "overwrite_file": false
    }
```

### Camera

In order to define a camera, you must specify the arguments `width` and `height`, besides 3 three-dimensional vectors named `position`, `target` and `up`, which defines the position of the camera.

```json
{
    "width": 200,
    "height": 100,
    "position":  [0, 0, 0], 
    "target": [0,0,-10], 
    "up": [0,1,1],
    ...
}
```

There are two types of camera that can be used: `orthographic` and `perspective`.

#### Orthographic
 The type `orthographic`requires a parameter `vdim`, that expects a four-dimensional array that 
 defines, respectively, the left, right, bottom and top, that together inform the pane dimensions.

```json
{
    "type":"orthographic",
    "width": 40,
    "height": 30,
    "position":  [0, 0, 0], 
    "target": [0,0,-10], 
    "up": [0,1,1],
    "vdim": [-3, 3, -2.25, 2.25]
}
```

#### Perspective
The type `perspective` expects 3 specific parameters: `fovy`, the vertical field of view; `aspect`, a optional parameter that define the aspect ration W/H; and `fdistance`, the focal distance.

```json
{
    "type":"perspective",
    "width": 40,
    "height": 30,
    "position":  [0, 0, 0], 
    "target": [0,0,-10], 
    "up": [0,1,1],
    "fovy": 45.0,
    "aspect": 1.33,
    "fidstance":1
}
```

### Background

When defining a background, you can have two types: solid and gradient.

#### Solid
The `type` argument is `solid` and the `color` expects a list with the values of red, green and blue, respectively.

```json
{
    "type": "solid",
    "color": [151, 12, 232]
}
```

#### Gradient
The `type` argument is `gradient` and the `colors` expects 4 lists with the values of red, green and blue, respectively. Each color define a corner, in this order: bottom-left, top-left, top-right, bottom-right.

```json
{
    "type": "gradient",
    "colors":[
        [0, 0, 51],
        [0, 255, 51],
        [255, 255, 51],
        [255,0,51]
    ]
}
```

### Integrators

Integrators are algorithms that determines the total incoming radiance at each rays's origin. An integrator may be physically based, an approximation of a physical model, or just an artistic expression.

#### FlatIntegrator

With this integrator, each point of a figure/shape is painted with the same color.
In order to use this integrator, it's only necessary to set the parameter `type` inside the `integrator` object to `flat`. The configuration of a integrator is placed inside the `running` object.

```json
{
    "running":{
        "integrator": {
            "type":"flat",
            "spp":1
        }
    }
}
```

#### DepthMapIntegrator

This integrator produces a gray scale image representing the depth map of the scene, by normalizing the hit value and using this value to linearly interpolate a color between white and black. The parameter `type` inside the `integrator` object must have the value `depth_map`. This algorithm also require a `far_color` and a `near_color`, each expecting a rgb object.

```json
{
    "running":{
        "integrator": {
            "type":"depth_map",
            "spp":1,
            "near_color":{"r": 0, "g":0, "b":0},
            "far_color":{"r": 0, "g":255, "b":0}
        }
    }
}
```

#### NormalMapIntegrator

Using this integrator the color of a hit is determined by making the normal at the hit point have length 1, and treating its coordinate values as RGB color. The parameter `type` must have the value `normal`.

```json
{
    "running":{
        "integrator": {
            "type":"normal",
            "spp":1
        }
    }
}
```

### Materials
Materials represent the behavior of light rays when they interact with a medium. The materials of a scene are defined inside a `materials` objects that expects an array. Each material has a `type` and a `name` that will be referenced for a shape.

#### FlatMaterial

FlatMaterial is the one used for the FlatIntegrator. Besides the parameters mencioned above, it also has a parameter called `diffused` that consists of a rgb object.

```json
{
    "type":"flat", "name":"pink",
    "diffuse":
        {
            "r":253, "g":153, "b":253
        }
}
```

