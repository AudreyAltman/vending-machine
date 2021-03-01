for i in {1..99}
do
  rem=$(($i % 2))
  if [ "$rem" -ne "0" ]; then
    curl -d "city_id="$i http://127.0.0.1:8080/
  fi
done
