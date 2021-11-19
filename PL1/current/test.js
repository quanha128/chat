function voting_right(){
    var elem1 = document.getElementById("age");
    var elem2 = document.getElementById("year");
    var elem3 = document.getElementById("result");
    var age = parseInt(elem1.textContent, 10);
    var year = parseInt(elem2.textContent, 10);
    console.log(elem1.textContent);
    console.log(year);
    if (year<2016 && age >=20) elem3.textContent = "You have right to vote";
    if (year>=2016 && age >=18) elem3.textContent = "You have right to vote";
    else elem3.textContent = "You have no right to vote";
}