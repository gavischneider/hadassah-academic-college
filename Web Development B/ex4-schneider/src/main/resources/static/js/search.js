window.addEventListener("DOMContentLoaded", () =>{
    document.getElementById("search-button").addEventListener("click", search);
})

function searchUsersByName(query){
    fetch("http://localhost:8080/search/user", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((users) => {
        let container = document.getElementById("user-results-container");
        let searchUserList = document.createElement("ul");
        users.map((user) => {
            let newUser = document.createElement("li");
            newUser.innerHTML = user.username;
            searchUserList.append(newUser);
        })
        container.innerHTML = '';
        container.append(searchUserList);
    })
}

function searchMessagesByBody(query){
    fetch("http://localhost:8080/search/message/body", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        let container = document.getElementById("message-body-results-container");
        let searchMessageList = document.createElement("ul");
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + " " + message.body;
            searchMessageList.append(newMessage);
        })
        container.innerHTML = '';
        container.append(searchMessageList);
    })
}

function searchMessagesByUser(query){
    fetch("http://localhost:8080/search/message/user", {
        method: "POST",
        headers: {
            Accept: "application/json",
            "Content-Type": "application/json",
            "Access-Control-Origin": "*",
        },
        body: JSON.stringify({
            query: query
        })
    }).then((res) => {
        return res.json();
    }).then((messages) => {
        let container = document.getElementById("message-user-results-container");
        let searchMessageByUserList = document.createElement("ul");
        messages.map((message) => {
            let newMessage = document.createElement("li");
            newMessage.innerHTML = message.user + " " + message.body;
            searchMessageByUserList.append(newMessage);
        })
        container.innerHTML = '';
        container.append(searchMessageByUserList);
    })
}

function search(){
    let query = document.getElementById("query-input").value.trim();
    searchUsersByName(query);
    searchMessagesByBody(query);
    searchMessagesByUser(query);
}