var k = ["green", "yellow", "blue"];
var l = ["green", "yellow", "blue"];

function order() {
    for (var i = 0; i < 3; i++) {
        if (k[i] == l[i]) {} else {
            return false;
        }
    }
    return true;
}
if (order()) {
    console.log("Checking true");
} else {
    console.log("Checking false k=" + k + "l=" + l);
}