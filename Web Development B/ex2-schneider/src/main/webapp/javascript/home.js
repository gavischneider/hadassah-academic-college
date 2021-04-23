window.alert("In JS page");

//(() => {
    window.addEventListener("DOMContentLoaded", () => {
        window.alert("Working!")
        addQuestions();
    })

    function addQuestions() {
        fetch("LoadQuestionsServlet", {
            headers: {
                'Content-Type': 'application/json'
            }})
            .then(res => res.json())
            .then(resp => {

                let qs = "";
                resp.map(question => {
                    let q = question.text;
                    qs += q + "</br>";
                })

                document.getElementById("questionsContainer").innerHTML = qs;
            })
            .catch(e => {
                document.getElementById("questionsContainer").innerHTML = "Error fetching JSON from servler...";
            });
    }
//});