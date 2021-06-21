window.addEventListener("DOMContentLoaded", () =>{
    alert("Hello!!")
    getMessages();
})

function getMessages(){
    fetch("http://localhost:8080/message/last-five", {
        method: "GET",
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        // Add messages to DOM
        let messageContainer = document.getElementById("message-container");
        messages.map((message) => {
            alert(message.body);
        })
    })
}