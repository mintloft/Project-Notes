copy "%~1simple_shader.vs" "%~2simple_shader.vs"
copy "%~1simple_shader.fs" "%~2simple_shader.fs"
copy "%~1awesomeface.png" "%~2awesomeface.png"
copy "%~1container.jpg" "%~2container.jpg"
xcopy "%~1objects\" "%~2objects\" /E /Y
xcopy "%~1shaders\" "%~2shaders\" /E /Y