let component = ReasonReact.statelessComponent("PageCreator");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div>
        <h2> (ReasonReact.string("Url")) </h2>
        <input style=(ReactDOMRe.Style.make(~fontSize="18px", ())) />
      </div>
      <div>
        <h2> (ReasonReact.string("Content")) </h2>
        <textarea
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
      <SaveButton />
    </div>
};