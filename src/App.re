[%bs.raw {|require('./App.css')|}];

type route =
  | PageCreator
  | Page;

type state = {route, page: string};

type action =
| ChangeRoute(route)
| SetPage(string);

let reducer = (action, state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route, page: state.page})
  | SetPage(page) => ReasonReact.Update({route: state.route, page: page})
};


let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => PageCreator
  | ["workhorse"] => PageCreator
  | _ => Page
};

let getPage = (url: ReasonReact.Router.url) => 
switch url.path {
| [] => ""
| [_, ...__] => List.nth(url.path,0);
};

let component = ReasonReact.reducerComponent("App");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: PageCreator, page: ""},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) => {
        self.send(ChangeRoute(url |> mapUrlToRoute));
        self.send(SetPage(url |> getPage));
      }),
      ReasonReact.Router.unwatchUrl
    )
],
  render: self =>
    (
      switch self.state.route {
      | PageCreator => {
        <div>
          <div className="App">
            <PageCreator /> 
          </div>
          <Footer />
        </div>
      }
      | Page => <Page name=(self.state.page) />
      }
    )
 ,
};
