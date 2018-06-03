[@bs.module] external logo : string = "./../../logo.svg";

module AddPage = [%graphql
  {|
    mutation AddPage($name: String!,$content: String!){
      addPage(name: $name,content:$content){
        name,
        content
      }
    }
|}
];

type state = {
  url: string,
  content: string
};

type action =
  | ChangeUrl(string)
  | ChangeContent(string);

let component = ReasonReact.reducerComponent("Form");

module AddPageMutation = ReasonApollo.CreateMutation(AddPage);

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
      <AddPageMutation>
      ...(
           (mutation, {result}) =>
          <SaveButton 
          isDisabled=(String.length(self.state.url) == 0 || String.length(self.state.content) == 0 )
          onBtnClick=(_ => {
            if(String.length(self.state.url) > 0 || String.length(self.state.content) > 0 )
            {
              let variables = AddPage.make(~name=self.state.url, ~content=self.state.content, ());
              mutation(
                ~variables=variables##variables,
                (),
              )
              |> _ => ReasonReact.Router.push("/"++self.state.url);
            }
            
          }) />
           
         )
    </AddPageMutation>
    </div>
};