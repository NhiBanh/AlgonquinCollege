<?php
  //artist data:  artist_id, artist_name, nationality, year_of_birth, year_of_death, description, wikipedia_link
  $artistsArr = array();//array to store all artists

  //Read file as string
  $preartistFile = file_get_contents('./resources/artists.txt');

  //convert the file encoding
  $artistFile =mb_convert_encoding($preartistFile, 'UTF-8', mb_detect_encoding($preartistFile, 'UTF-8, ISO-8859-1', true));

  //add each line as string into array
  $lines = explode(PHP_EOL, $artistFile);

  //iterate through each line, and populate artists array
  foreach($lines as $line){
    //convert line into array
    $artistArr = explode("~", $line);

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
  $paintingsArr = array();//array to store all paintings

  //Read file as string
  $prePaintingFile = file_get_contents('./resources/paintings.txt');

  //convert the file encoding
  $paintingFile  = mb_convert_encoding($prePaintingFile, 'UTF-8', mb_detect_encoding($prePaintingFile, 'UTF-8, ISO-8859-1', true));

  //add each line as string into array
  $lines = explode(PHP_EOL, $paintingFile);

  //iterate through each line, and populate artists array
  foreach($lines as $line){
    //convert line into array
    $paintingArr = explode("~", $line);

    //create artist data array
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
    //add the painting data to the paintings array
    array_push($paintingsArr, $painting);
  }

  //filered paitings array
  $filPaitingsArr = array();

  if(!empty($_GET["genre"])){
    //get all the keys of array that matches genre query string
    $matchPaitings = array_keys(array_column($paintingsArr, 'genre_name'), $_GET["genre"]);

    //iterate through matching paitings keys
    foreach($matchPaitings  as $matchIndex){
      //add painting into filtered paiting array via index
      array_push($filPaitingsArr, $paintingsArr[$matchIndex]);
    }
  }else{
    //add all paitings to show no filter
    $filPaitingsArr = $paintingsArr;
  }
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>Assign2-Home Page of Art Gallery</title>
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
    <?php foreach($filPaitingsArr as $painting){
        $artKey = array_search($painting['artist_name'], array_column($artistsArr, 'artist_name'));
      ?>
      <div class="painting-listing">
        <img src="resources/paintings/square-medium/<?php echo $painting['painting_id']; ?>.jpg" >
        <a href="singlePainting.php?id=<?php echo $painting['painting_id']; ?>"><?php echo $painting['title']; ?></a>
        <a href="singleArtist.php?id=<?php echo $artistsArr[$artKey]['artist_id']; ?>" style="float:right; width:15%;"><?php echo $painting['artist_name']; ?></a>
      </div>
    <?php } ?>
	</div>
	<div class="clear"> </div>
</div>
</body>
</html>
