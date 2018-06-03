[%bs.raw {|require('./App.css')|}];

type route =
  | PageCreator
  | Page;

type state = {route};

type action =
| ChangeRoute(route);

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
};


let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => PageCreator
  | _ => Page
};

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: PageCreator},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => self.send(ChangeRoute(url |> mapUrlToRoute))),
      ReasonReact.Router.unwatchUrl
    )
],
  render: self =>
    <div className="App">
    (
      switch self.state.route {
      | PageCreator => <PageCreator />
      | Page => <Page />
      }
    )
    </div>,
};
