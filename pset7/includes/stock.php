<?php
	// Stock.php	CC50	Pset7	Define uma classe (ou seja, estrutura) para uma ação.

	class Stock
	{
		// nome da ação
		public $name = NULL;

		// símbolo da ação
		public $symbol = NULL;

        // preço mais recente da ação
        public $price = NULL;

		// baixa do dia mais recente
		public $low = NULL;

		// alta do dia mais recente
		public $high = NULL;

		/*
		// time at which the stock last changed hands (measured in the number
		// of seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)
		public $time = NULL;

		// percent by which the stock's price changed over the course 
		// of the most recent (business) day 
		public $change = NULL;

		// most recent (business) day's opening price
		public $open = NULL;
		*/
	}
?>
