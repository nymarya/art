# art
Another Ray Tracer


## How to use

|  Command           | Description  |
| :-----| :-------------|
| ```$ make``` | Compile |
| ```$ ./canvas.out``` | Run | 


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

In order to define a camera, you must specify the arguments `width` and `height`.

> Work in progress

```json
{
    "width": 200,
    "height": 100
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


