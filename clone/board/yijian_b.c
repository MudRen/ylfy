
inherit BULLETIN_BOARD;
void create()
{
set_name("����ͨ����", ({"tonggao lan"}) );
set("location", "/d/city2/wenmiao");        	
set("board_id", "yijian_b");	
    set("no_get",1);
  set("long","����һ����������������������İװ档\n");

	setup();
	set("unit","��");
        set("capacity", 218);
replace_program(BULLETIN_BOARD);
}
