$.ajax({
    url: "http://marinesnow.sakura.ne.jp/2019/sample.php",
    type: "GET",
    async: "false",
    success: function(data) {
        for (var i in data) {
            $("#scoredata").append(        // following contents are appended to “scoredata”
        "<li>"                       // <li> tag 
        + data[i].subject            // value of the property "subject"
        + ":" + data[i].score + " "    // ":" and the value of "score"
        + "(" + data[i].result + ")"   // value of "result" with brackets
        + "</li>");                    // close </li> tag
        }
    }
});
