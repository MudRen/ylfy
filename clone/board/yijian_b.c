
inherit BULLETIN_BOARD;
void create()
{
set_name("江湖通告栏", ({"tonggao lan"}) );
set("location", "/d/city2/wenmiao");        	
set("board_id", "yijian_b");	
    set("no_get",1);
  set("long","这是一块用来公布江湖新增案议的白版。\n");

	setup();
	set("unit","块");
        set("capacity", 218);
replace_program(BULLETIN_BOARD);
}
