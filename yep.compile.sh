echo "Enable QT on your terminal"
echo "export the env"
echo "Don't execute \"qmake -project\""
echo "Otherwise: added "
read -p "right?"
qmake
make
