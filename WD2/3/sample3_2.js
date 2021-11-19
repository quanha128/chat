function save_data() {
    let key1=document.getElementById('key1').value;
    let value1=document.getElementById('value1').value;
    localStorage.setItem(key1, value1);
}

function read_data() {
    for (let i=0; i < localStorage.length; ++i) {
        document.getElementById('display_data').innerHTML += 
            localStorage.key(i)
            + ' : '
            + localStorage.getItem(localStorage.key(i))
            + '<br>'
            ;
    }
}