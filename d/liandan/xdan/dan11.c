inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("还魂丹", ({"huanhun dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗黑呼呼的药丸。\n");
        }
}
int do_eat(string arg)
{
        string *skills;
        mapping all_skills;
        int i;
        if (!id(arg))
             return notify_fail("你要吃什么药？\n");
 else{
  if(this_player()->query("id")==query("value"))
 return notify_fail("这棵丹不是你练的,你吃个什么劲。\n");

        all_skills=this_player()->query_skills();
        if (!sizeof(all_skills))  destruct(this_object());
        skills=keys(all_skills);
        for(i=0;i<sizeof(skills);i++)
                this_player()->set_skill(skills[i],all_skills[skills[i]]+1);
        this_player()->add("combat_exp", 100000);
        this_player()->add("potential", 50000);
        message_vision("$N吃下一颗还魂丹,从白无常那里拣回了条小命回来。\n", this_player());
		log_file("static/EAT_DAN",sprintf("%s 吃了黑子做的回魂丹 %s\n", this_player()->query("id"), ctime(time())) );
        destruct(this_object());
        return 1;
        }
}

