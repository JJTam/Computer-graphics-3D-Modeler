# COMP4411-Project2-Modeler

<p>A hierarchical model is a way of grouping together shapes and attributes to form a complex object. Parts of the object are defined in relationship to each other as opposed to their position in some absolute coordinate system. Think of each object as a tree, with nodes decreasing in complexity as you move from root to leaf. Each node can be treated as a single object, so that when you modify a node you end up modifying all its children together. Hierarchical modeling is a very common way to structure 3D scenes and objects, and is found in many other contexts.</p>
<p>In this project you define a 3D model and controls for moving it, and then display and operate the model. The project skeleton contains the framework code for the UI as well as some functions for drawing primitives. You will specify your model in a separate source file that will be compiled and linked in with the existing code. Also, you will use OpenGL to create and animate a character of your own design. You will become familiar with 3D hierarchical modeling and transformations.</p>


## Project Requirements
<p>First of all, you must come up with a character. This character can be composed solely of primitive shapes (<b>box, generalized cylinder, sphere, and triangle</b>).  It should use at least ten primitives and at least four levels of hierarchy. You must also use at least one each of the <b>glTranslate(), glRotate() and glScale()</b> calls to position these primitives in space (and you will probably use many of all of them!) You must also use <b>glPushMatrix() and glPopMatrix()</b> to nest your matrix transformations. The modeler skeleton provides functions for creating sliders and hooking them to different features of your model. You must add at least one of these as a control knob (slider, actually) for some joint/component of your model - have your character do some simple action as you scrub a slider back and forth. In addition, at least one of your controls must be tied to more than one joint/component; this knob will change the input to some function that determines how several parts of your model can move. For example, in a model of a human, you might have a slider that straightens a leg by extending both the knee and hip joints.</p>
<p>In the Camera class, the function called <b>applyViewingTransform()</b> uses <b>gluLookAt()</b> to perform a viewing transform that effectively moves the camera to the specified position and orientation. You are required to implement your own version of <b>gluLookAt()</b> using any method <b>(i.e. the standard transformations (glTranslate, glRotate, glScale), matrix construction)</b> as long as you are not using the gluLookAt itself. Add a function to the Camera class with the following prototype:</p>
<p><b>void Camera::lookAt(double *eye, double *at, double *up)</b></p>
<p>where <b>eye, at and up</b> are each 3 element arrays that specify the position of the camera, the point it is looking at and the up vector in world co-ordinates. Using these arguments, your function should apply a series of translations and rotations (or construct a matrix) that effectively moves the camera to the specified position and orientation.</p>
<p>You are required to complete two bells (or equivalent) from the list below. Feel free to come up with your own ideas and pass them by us. If they're cool, we'll count them as bells and whistles.</p>
<p>Other than these requirements, you have complete artistic freedom on this, so be creative!</p>


## Warning
<p>Editing <b>modeler*.*</b> is strongly discouraged. For project 4 you will be using you new model source file and plugging it into a different application. If your model depends on changes to <b>modeler*.*</b> it may not be compatible with project 4.</p>


## Bells and Whistles
<pre style="word-wrap: break-word; white-space: pre-wrap;">Modeler Bells and Whistles checklist for grading
(submit with your project ONLY if you have implemented any of the following B&amp;Ws)

HKUST login(s):

Basic requirements: 
Please state what 2B you implemented to exclude from your B/W scores below
B ______
B ______

B/W:

Delete yes/no when appropriate

W dramatic light					yes
W adjustable LoD					yes
W your idea 						yes/no
B texture map						yes/no
B polygonal faces (triangles)				yes/no 
B animation       					yes
B individual looking (not just red/green) 		yes/no
B frame all						yes/no 
BW up vector 						yes/no
2B new primitives for each 				yes/no
2B L-system						yes/no
2B mood cycling 					yes/no
4B metaballs						yes/no
8B goal-oriented motion 				yes/no
+4B joint contraints 					yes/no
</pre>
