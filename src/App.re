let component = ReasonReact.statelessComponent("App");

module VideoGames = [%graphql
  {|
query VideoGames {
    videoGames {
        id
        title
        developer
        completed
    }
}
|}
];

module VideoGamesQuery = ReasonApollo.CreateQuery(VideoGames);

let make = _children => {
  ...component,
  render: _self => {
    let videoGamesQuery = VideoGames.make();
    <div>
      <h1> {ReasonReact.string("ReasonML + ReasonReact + GraphQL")} </h1>
      <VideoGamesQuery variables=videoGamesQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> ReasonReact.string "Loading video games!" </div>
          | Error(error) => <div> ReasonReact.string {error##message} </div>
          | Data(data) => <VideoGameList items=data##videoGames />
          }
        }
      </VideoGamesQuery>
    </div>;
  },
};