# viam-csi
> viam module for csi cams

![](./etc/viam-server.png)

___

## CSI Camera Module

`viam-csi` is a [Viam module](https://docs.viam.com/extend/modular-resources/) for implementing CSI camera on Viam-powered machines.
It includes a simple wrapper around [GStreamer](https://gstreamer.freedesktop.org/documentation/?gi-language=c) and an interface that satisfies a [Viam Camera component](https://docs.viam.com/components/camera/). This means you can utilize the hardware accelerated GST plugins on your Jetson or Pi with the Viam ecosystem.

You can view more platform specific details at [JETSON.md](./doc/JETSON.md) and [PI.md](./doc/PI.md).

_Note: On a Raspberry Pi, you must install GStreamer plugins before running the module._

_WARNING: There is a known issue for Debian Bookworm due to changes in the libcamerasrc plugin._
___

## Usage

To use this module, follow these instructions to [add a module from the Viam Registry](https://docs.viam.com/registry/configure/#add-a-modular-resource-from-the-viam-registry) and select the `viam:camera:csi` model from the [`csi-cam` module](https://app.viam.com/module/viam/csi-cam).

## Configure your CSI camera

> [!NOTE]  
> Before configuring your camera, you must [create a robot](https://docs.viam.com/manage/fleet/robots/#add-a-new-robot).

Navigate to the **Config** tab of your robot’s page in [the Viam app](https://app.viam.com/). Click on the **Components** subtab and click **Create component**. Select the `camera` type, then select the `csi` model. Enter a name for your camera and click **Create**.

On the new component panel, copy and paste the following attribute template into your camera's **Attributes** box. 
```json
{
  "width_px": <int>,
  "height_px": <int>,
  "frame_rate": <int>,
  "debug": <bool>
}
```

> [!NOTE]  
> For more information, see [Configure a Robot](https://docs.viam.com/manage/configuration/).

Edit the attributes as applicable and save your config.
In the **Control** tab of the [Viam app](https://app.viam.com/), you can now view the camera feed. 
If you do not see anything, check the logs tab for errors.

### Attributes

The following attributes are available for `viam:camera:csi` cameras:

<!-- prettier-ignore -->
| Name | Type | Inclusion | Description |
| ---- | ---- | --------- | ----------- |
| `width_px` | int | Optional | Width of the image this camera captures in pixels. <br> Default: `1920` |
| `height_px` | int | Optional | Height of the image this camera captures in pixels. <br> Default: `1080` |
| `frame_rate` | int | Optional | The image capture frame rate this camera should use. <br> Default: `30` |
| `video_path` | string | Optional | The filepath to the input sensor of this camera on your board. If none is given, your robot will attempt to detect the video path automatically. <br> Default: `"0"` </br>  |
| `debug` | boolean | Optional | Whether or not you want debug input from this camera in your robot's logs. <br> Default: `false` |

### Example Configuration

```json
{
  "modules": [
    {
      "executable_path": "/usr/local/bin/viam-csi",
      "name": "csi_cam_module"
    }
  ],
  "components": [
    {
      "model": "viam:camera:csi",
      "attributes": {
        "width_px": 1920,
        "height_px": 1080,
        "frame_rate": 30,
        "debug": true
      },
      "depends_on": [],
      "name": "csicam_test",
      "namespace": "rdk",
      "type": "camera"
    }
  ]
}
```
___

### Build from local appimage

To install the latest development version of the module, run the following commands:
```bash
sudo wget http://packages.viam.com/apps/csi-camera/viam-csi-latest-aarch64.AppImage -O /usr/local/bin/csi-cam
```

```bash
sudo chmod 755 /usr/local/bin/csi-cam
```

See [local-app-config.json](./etc/local-app-config.json) for how to configure with local csi-cam appimage.
___

### Develop

View [DEVELOP.md](./doc/DEVELOP.md) for more information on how to build and run the module locally or in Docker. Pull Requests and Issues are welcome!

___

### Support

- [x] [Nvidia Jetson](./doc/JETSON.md)
- [x] [Raspberry Pi](./doc/PI.md)
- [ ] Orange Pi
