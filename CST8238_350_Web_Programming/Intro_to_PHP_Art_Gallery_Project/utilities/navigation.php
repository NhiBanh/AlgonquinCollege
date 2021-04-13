<div id="genreListing">
	<h2>Genres</h2>
	<ul class="secondaryList">
		<?php
		//get all genre_names from paintings array
		$genreNamesArr = array_column($paintingsArr, 'genre_name' );

		//get unique values from sorted $genreNamesArr
		$genreArr = array_unique($genreNamesArr);

		//sort the array alphabetically
		asort($genreArr);

		//print off each genre
		foreach($genreArr as $genre){ ?>
				<li><a href="index.php?genre=<?php echo urlencode($genre); ?>"><?php echo $genre; ?></a></li>
		<?php } ?>
	</ul>
</div>

<div id="artistListing">
	<h2>Artists</h2>
	<ul class="secondaryList">
		<?php foreach($artistsArr as $artist){ ?>
				<li><a href="singleArtist.php?id=<?php echo $artist['artist_id']; ?>"><?php echo $artist['artist_name']; ?></a></li>
		<?php } ?>

	</ul>
</div>
