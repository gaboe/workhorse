[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string("WorkHorse")) </h2>
      </div>
        <p className="App-intro">
        (ReasonReact.string("WorkHorse lets you create a custom page."))
      </p>
      <PageCreator />
    </div>,
};
