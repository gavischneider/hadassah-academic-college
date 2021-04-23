//(() => {
    window.addEventListener("DOMContentLoaded", () => {
        addQuestions();
    })

    function addQuestions() {
        fetch("LoadQuestionsServlet", {
            headers: {
                'Content-Type': 'application/json'
            }})
            .then(res => res.json())
            .then(resp => {

                let container = document.getElementById("questionsContainer");
                let questions = "";
                resp.map(question => {
                    // div is the container for the question
                    let div = document.createElement("div");

                    // Add the question text to the container
                    let text = document.createElement("div");
                    text.innerHTML = question.text;
                    text.setAttribute("class", "alert");
                    text.setAttribute("class", "alert-primary");
                    div.appendChild(text);
                    let br = document.createElement("br");
                    container.appendChild(div);
                    container.appendChild(br);

                    // Add the number of questions and two buttons - show and answer
                    let bottomRow = document.createElement("div");
                    bottomRow.setAttribute("class", "d-flex");
                    let numOfAnswers = document.createElement("p");
                    numOfAnswers.setAttribute("class", "numOfAnswers");
                    numOfAnswers.innerText = "0 answers";
                    let showButton = document.createElement("button");
                    showButton.setAttribute("type", "button");
                    showButton.setAttribute("class", "btn");
                    showButton.setAttribute("class", "btn-primary");
                    showButton.innerText = "Show";
                    showButton.setAttribute("class", "showButton");
                    let answerButton = document.createElement("button");
                    answerButton.setAttribute("type", "button");
                    answerButton.setAttribute("class", "btn");
                    answerButton.setAttribute("class", "btn-info");
                    answerButton.innerText = "Answer";
                    answerButton.setAttribute("class", "answerButton");
                    bottomRow.appendChild(numOfAnswers);
                    bottomRow.appendChild(showButton);
                    bottomRow.appendChild(answerButton);
                    container.appendChild(bottomRow);
                })

                //document.getElementById("questionsContainer").innerHTML = questions;
            })
            .catch(e => {
                document.getElementById("questionsContainer").innerHTML = "Error fetching JSON from servlet...";
            });
    }
//});