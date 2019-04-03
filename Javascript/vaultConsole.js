$(document).ready(
  function getDirectoryInformation(){
    var _location = document.location.toString();
    var vIndex = _location.indexOf('/', _location.indexOf('://') + 3);
    var vDirectory = _location.substring(0, vIndex) + '/';

    console.log("Location: " + _location);
    console.log("Directory: " + vDirectory);
  }
)