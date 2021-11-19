function compute() {
    var inputR = document.getElementById('input-radius');
    var inputD = document.getElementById('input-degree');
    var r = parseFloat(inputR.value);
    var d = parseFloat(inputD.value);

    console.log(r)
    console.log(d)

    var area = Math.PI*r**2 * d/360;
    var arc = 2*Math.PI*r * d/360;

    var spanArea = document.getElementById('area');
    var spanArc = document.getElementById('arc');
    spanArea.textContent = area;
    spanArc.textContent = arc;
}  