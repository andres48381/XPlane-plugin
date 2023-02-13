# XPlane-plugin
Plugin  for X-Plane 11 compiled with Qt y C++. It posts a new int dataref and read the value.

# How to build and install it
- This project is based on Qt 5 or greather. You can donwload it from https://download.qt.io/archive/qt/
- Open Qt Creator and import the project, then configure the release folder to generate de plugin 
- Modify the generated .dll file name (plugin) to "win.xpl"
- Paste the file win.xpl in "X-Plane/resources/plugins/myplugin"

# How to verify it:
- A usefull tool for X-Plane is the plugin https://datareftool.com/. Donwload and install it as any plugin.
- Launch X-Plane and click on Plugin section, then open DatarefTool.
- It is possible to watch and modify the dataref value in the plugin display. Only type "andres/example"...

<img src="https://datareftool.com/datareftool.png" width=50% height=50%>
