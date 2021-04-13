<?php
//artist data:  artist_id, artist_name, nationality, year_of_birth, year_of_death, description, wikipedia_link
$artistsArr = array(); //array to store all artists


//Read file as string
$preartistFile = file_get_contents('./resources/artists.txt');

//convert the file encodings
$artistFile = mb_convert_encoding($preartistFile, 'UTF-8',mb_detect_encoding($preartistFile, 'UTF-8, ISO-8859-1', true));

//add each line as string into array
$lines = explode(PHP_EOL, $artistFile);

//iterate through each line, and populate artists array
foreach ($lines as $line) {
  //convert line into array
  $artistArr = explode("~",$line);

  //create artist data array
  $artist = array(
    'artist_id' => $artistArr[0],
    'artist_name' => $artistArr[1],
    'nationality' => $artistArr[2],
    'year_of_birth' => $artistArr[3],
    'year_of_death' => $artistArr[4],
    'description' => $artistArr[5],
    'wikipedia_link' => $artistArr[6],
  );

  //add the artist data to the artists array
  array_push($artistsArr, $artist);
}

//paintings data: painting_id, artist_name, title, year, width, height, price, description, wikipedia_link, genre_name
$paintingsArr = array(); //array to store all paintings

//Read file as string
$prePaintingFile = file_get_contents('./resources/paintings.txt');

//convert the file encoding
$paintingFile  = mb_convert_encoding($prePaintingFile, 'UTF-8', mb_detect_encoding($prePaintingFile, 'UTF-8, ISO-8859-1', true));

//add each line as string into array
$lines = explode(PHP_EOL, $paintingFile);

//iterate through each line, and populate artists array
foreach($lines as $line){
  //convert line into array
  $paintingArr = explode("~",$line);

  $painting = array(
    'painting_id' => $paintingArr[0],
    'artist_name' => $paintingArr[1],
    'title' => $paintingArr[2],
    'year' => $paintingArr[3],
    'width' => $paintingArr[4],
    'height' => $paintingArr[5],
    'price' => $paintingArr[6],
    'description' => $paintingArr[7],
    'wikipedia_link' => $paintingArr[8],
    'genre_name' => $paintingArr[9],
  );

  //add the paiting data to the paintings array
  array_push($paintingsArr, $painting);
}

if(!empty($_GET["id"])){
  //get the key of the artist in the artists array
  $artistKey = array_search($_GET["id"], array_column($artistsArr, 'artist_id'));

  //get the artist
  $curartist = $artistsArr[$artistKey];
}

//get all the keys of artists paitings in paintins array to display on page
$artPaintKeys = array_keys(array_column($paintingsArr, 'artist_name'), $curartist['artist_name']);

$artistsPaintings = array();

//iterate through artists paint keys
foreach($artPaintKeys  as $paintKey){
  //add artists painting into paitings array via paint key
  array_push($artistsPaintings, $paintingsArr[$paintKey]);
}

?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
  <head>
    <title>Assign2 - Single Artist</title>
    <link rel="stylesheet" href="css/reset.css" />
    <link rel="stylesheet" href="css/text.css" />
    <link rel="stylesheet" href="css/960.css" />

    <link rel="stylesheet" href="css/assign2.css" />
  </head>

  <body>

    <div class="container_12">
    	<?php require_once("utilities/header.php"); ?>
    	<div class="grid_3">
    		<?php require_once("utilities/navigation.php"); ?>
    	</div>
    	<div class="grid_9">

        <div style="margin-left: 40px;">
          <img src="resources/artists/large/<?php echo $curartist['artist_id']; ?>.jpg" >
          <h3 ><?php echo $curartist['artist_name']; ?></h3>
          <p style="font-style: italic;" ><?php echo $curartist['year_of_birth']. ' - ' .$curartist['year_of_death']; ?>
          <br/><?php echo '('.$curartist['nationality'].')'; ?></p>
          <p><?php echo $curartist['description']; ?></p>
        </div>
        <a href="<?php echo $curartist['wikipedia_link']; ?>" target="_blank"><?php echo $curartist['artist_name']; ?> on Wikipedia</a>
        <br/><br/>
        <h4>Paintings</h4>
        <?php
        //loop through the artists paintings
        foreach($artistsPaintings as $artpaint){
          echo '<li><a href="singlePainting.php?id='. $artpaint['painting_id']. '">' .$artpaint['title'].'</li>';
        }
        ?>
        <br>
    	</div>
    	<div class="clear"> </div>
    </div>
  </body>
</html>
