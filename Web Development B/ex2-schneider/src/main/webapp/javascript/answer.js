// Add the question id passed in the url to the form
window.addEventListener("DOMContentLoaded", () => {
    let questionId = getUrlParameter('question');
    let questionInput = document.getElementById("questionInput");
    questionInput.value = questionId;
})

function getUrlParameter(parameter) {
    let pageUrl = window.location.search.substring(1);
    let urlVariables = pageUrl.split('&');
    for (let i = 0; i < urlVariables.length; i++)
    {
        let parameterName = urlVariables[i].split('=');
        if (parameterName[0] === parameter)
        {
            return parameterName[1];
        }
    }
}
