// dog.c
// adams: 1998/06/20

inherit NPC;

void create()
{
        set_name("宠物狗", ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
        set("long", "一只浑身长了白毛的宠物狗。\n");
	
	set("str", 32);
	set("dex", 36);

	set("chat_msg", ({
		(: this_object(), "random_move" :),
                "宠物狗用鼻子闻了闻你的脚。\n",
                "宠物狗在你的脚边挨挨擦擦的，想讨东西吃。\n",
                "宠物狗对著你摇了摇尾巴。\n",
                "宠物狗用後腿抓了抓自己的耳朵。\n" }) );
		
	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
		return 1;
	}
}
