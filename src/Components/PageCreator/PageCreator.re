let component = ReasonReact.statelessComponent("PageCreator");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <div> <h2> (ReasonReact.string("Url")) </h2> <input /> </div>
      <div>
        <h2> (ReasonReact.string("Content")) </h2>
        <textarea cols=80 rows=15 />
      </div>
      <SaveButton />
    </div>
};