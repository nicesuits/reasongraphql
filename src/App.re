let str = ReasonReact.string
let component = ReasonReact.statelessComponent("App")

let make = _children=>{
    ...component,
    render: _self=>
    <div>
        <h1>{"ReasonML + ReasonReact + GraphQL" |> str}</h1>
    </div>
}