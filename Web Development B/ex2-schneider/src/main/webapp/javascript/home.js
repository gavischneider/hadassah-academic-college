window.addEventListener("DOMContentLoaded", () => {
    addQuestions();
})

// This function adds questions from the file to the home page. It gets called when the DOM content is loaded
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
                container.appendChild(div);

                // Add the number of questions and two buttons - show and answer
                let bottomRow = document.createElement("div");

                let numOfAnswers = document.createElement("p");
                let num = question.answers;
                numOfAnswers.innerText = num + " answers";

                let showButton = document.createElement("button");
                showButton.addEventListener("click", showAnswers);
                showButton.setAttribute("type", "button");
                showButton.setAttribute("class", "btn");
                showButton.setAttribute("class", "btn-primary");
                showButton.setAttribute("class", "me-3");
                showButton.innerText = "Show";

                let answerButton = document.createElement("button");
                answerButton.addEventListener("click", answerQuestion);
                answerButton.setAttribute("type", "button");
                answerButton.setAttribute("class", "btn");
                answerButton.setAttribute("class", "btn-info");
                //answerButton.setAttribute("class", "ml-50");
                answerButton.innerText = "Answer";

                // Add the question id
                let questionId = document.createElement("div");
                questionId.innerText = question.id;
                questionId.setAttribute("class", "d-none");

                bottomRow.appendChild(numOfAnswers);
                bottomRow.appendChild(showButton);
                bottomRow.appendChild(answerButton);
                bottomRow.appendChild(questionId);
                bottomRow.setAttribute("class", "d-flex");
                bottomRow.setAttribute("class", "justify-content-around")
                bottomRow.setAttribute("class", "p-3");

                let br = document.createElement("br");
                container.appendChild(bottomRow);
                container.appendChild(br);
            })
        })
        .catch(e => {
            document.getElementById("questionsContainer").innerHTML = "Error fetching JSON from servlet..." + e;
        });
}

// Check which question is being answered and redirect
function answerQuestion(e) {
    let question = e.path[1].childNodes[3].innerHTML;
    window.location = '/html/answer.html?question=' + question;
}

// Get all answers for a particular question
function showAnswers(e) {
    // Remove show button
    let showButton = e.path[1].childNodes[1];
    showButton.classList.add("d-none");

    // Create DOM element for answers
    let answersContainer = document.createElement("div");
    let title = document.createElement("h4");
    title.innerText = "Answers: ";
    let hide = document.createElement("button");
    hide.innerHTML = "Hide Answers";
    hide.setAttribute("class", "btn");
    hide.setAttribute("class", "btn-secondary");
    hide.addEventListener("click", hideAnswers);
    let br = document.createElement("br");
    answersContainer.appendChild(br);
    answersContainer.appendChild(hide);
    answersContainer.appendChild(title);

    // Fetch answers from servlet and loop through them
    let q = e.path[1].childNodes[3].innerHTML;
    let url = new URL("http://localhost:8080/AnswersServlet"),
        params = {question:q}
    Object.keys(params).forEach(key => url.searchParams.append(key, params[key]))

    fetch(url, {
        headers: {
            'Content-Type': 'application/json'
        }})
        .then(res => res.json())
        .then(resp => {
            // Loop through all the answers that were returned
            resp.map(answer => {
                let a = document.createElement("p");
                let user = answer.user;
                let text = answer.text;
                let u  = "[" + user + "]";
                a.innerText = u + " " + text;
                answersContainer.appendChild(a);
            })

            // Add answers to DOM
            let question = e.path[1];
            question.appendChild(answersContainer);
        })
}

// Remove answers from DOM
function hideAnswers(e) {
    // Return show button
    e.path[2].childNodes[1].classList.remove("d-none");

    // Hide the answers
    e.path[2].removeChild(e.path[2].childNodes[4]);
}

