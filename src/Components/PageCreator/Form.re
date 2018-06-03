[@bs.module] external logo : string = "./../../logo.svg";

type state = {
  url: string,
  content: string
};

type action =
  | ChangeUrl(string)
  | ChangeContent(string);

let component = ReasonReact.reducerComponent("Form");

let make = _children => {
  ...component,
  initialState: () => {url: "", content: ""},
  reducer: (action, state) =>
    switch action {
    | ChangeUrl(text) => ReasonReact.Update({...state, url: text})
    | ChangeContent(text) => ReasonReact.Update({...state, content: text})
    },
  render: self =>
    <div>
      <div>
        <h2> (ReasonReact.string("Url")) </h2>
        <input
          onChange=(
            event =>
              self.send(
                ChangeUrl(
                  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value
                )
              )
          )
          style=(ReactDOMRe.Style.make(~fontSize="18px", ()))
        />
      </div>
      <div>
        <h2> (ReasonReact.string("Content")) </h2>
        <textarea
          onChange=(
            event =>
              self.send(
                ChangeContent(
                  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value
                )
              )
          )
          style=(
            ReactDOMRe.Style.make(
              ~borderWidth="0px",
              ~backgroundColor="rgb(240, 233, 233)",
              ~fontSize="18px",
              ()
            )
          )
          cols=80
          rows=15
        />
      </div>
      <SaveButton onBtnClick=(_ => Js.log("click")) />
    </div>
};