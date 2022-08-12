#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/tbtk/auv_ws/src/uuv_simulator/uuv_control/uuv_auv_control_allocator"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/tbtk/auv_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/tbtk/auv_ws/install/lib/python3/dist-packages:/home/tbtk/auv_ws/build/uuv_auv_control_allocator/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/tbtk/auv_ws/build/uuv_auv_control_allocator" \
    "/usr/bin/python3" \
    "/home/tbtk/auv_ws/src/uuv_simulator/uuv_control/uuv_auv_control_allocator/setup.py" \
     \
    build --build-base "/home/tbtk/auv_ws/build/uuv_auv_control_allocator" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/tbtk/auv_ws/install" --install-scripts="/home/tbtk/auv_ws/install/bin"
