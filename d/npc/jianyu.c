// Room: /d/gvmt/jianyu_do.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "牢营监狱");
	set("long", @LONG
这里黑沉沉的，即无一丝光亮，也无半分声息。黑暗中依稀
可以看到身边似乎有几个人影，看到你转过头去，他们立刻屏住
呼吸，紧张地瞪着你。四壁冰凉，只有一道小门，门上开了个巴
掌大的洞，象是送饭用的。脚边有一堆东西踢上去克剌剌地散了
开来，细看却是一具白得发亮的枯骨。
LONG
	);


        set("valid_startroom",1);
        

	setup();

}

void init()
{       
	object ob;
	
	if (interactive(ob = this_player()))
        {	
		if( (int)ob->query_condition("gvmt_jail") <= 0 )
		{
			message("vision",
				HIY "只听牢房铁门匡地一响，好象有人进来！\n\n" NOR, 
				environment(ob), ob);

			tell_object(ob, "狱卒在门外嘿嘿地笑着：今儿个你可落在我手里了...！\n");

			ob->set("startroom", "/d/gvmt/jianyu_do");
		
		}
	}
}
