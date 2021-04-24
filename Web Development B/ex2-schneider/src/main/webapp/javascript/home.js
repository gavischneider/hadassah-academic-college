//(() => {
    window.addEventListener("DOMContentLoaded", () => {
        addQuestions();
    })

    function addQuestions() {
        // Fetch questions from servlet and loop through them
        fetch("LoadQuestionsServlet", {
            headers: {
                'Content-Type': 'application/json'
            }})
            .then(res => res.json())
            .then(resp => {

                let container = document.getElementById("questionsContainer");
                resp.map(question => {
                    // div is the container for the question
                    let div = document.createElement("div");
                    div.setAttribute("class", "question");

                    // Add the question text to the container
                    let text = document.createElement("div");
                    text.innerHTML = question.text;
                    text.setAttribute("class", "alert");
                    text.setAttribute("class", "alert-primary");
                    div.appendChild(text);
                    let br = document.createElement("br");
                    container.appendChild(div);

                    // Add the number of questions and two buttons - show and answer
                    let bottomRow = document.createElement("div");


                    let numOfAnswers = document.createElement("p");

                    numOfAnswers.innerText = "0 answers";

                    let showButton = document.createElement("button");
                    showButton.addEventListener("click", showAnswers);

                    showButton.setAttribute("type", "button");
                    showButton.setAttribute("class", "btn");
                    showButton.setAttribute("class", "btn-primary");
                    showButton.innerText = "Show";


                    let answerButton = document.createElement("button");
                    answerButton.addEventListener("click", answerQuestion);

                    answerButton.setAttribute("type", "button");
                    answerButton.setAttribute("class", "btn");
                    answerButton.setAttribute("class", "btn-info");
                    answerButton.innerText = "Answer";

                    // Add the question id
                    let questionId = document.createElement("div");
                    questionId.innerText = question.id;



                    bottomRow.appendChild(numOfAnswers);
                    bottomRow.appendChild(showButton);
                    bottomRow.appendChild(answerButton);
                    bottomRow.appendChild(questionId);
                    bottomRow.setAttribute("class", "d-flex");
                    bottomRow.setAttribute("class", "justify-content-around")
                    bottomRow.setAttribute("class", "p-3");

                    container.appendChild(bottomRow);
                    container.appendChild(br);
                })
            })
            .catch(e => {
                document.getElementById("questionsContainer").innerHTML = "Error fetching JSON from servlet...";
            });
    }
    
    function answerQuestion(e) {
        let question = e.path[1].childNodes[3].innerHTML;
        window.location = '/html/answer.html?question=' + question;
        console.log("Event: ");
        console.log(e.path[1].childNodes[3].innerHTML);
    }
    
    function showAnswers() {
        window.alert("Show Answers")
    }
//});
