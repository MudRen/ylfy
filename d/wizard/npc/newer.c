// newer.c
inherit NPC;
void create()
{
set_name("新闻发布使",({ "newer" }) );	
set("gender", "男性" );
set("age", 15);
set("long", 	CYN"他是夕阳再现之风云再起的新闻发布使者，江湖里的通知都由他来发布\n");
set("max_qi", 5000000);
set("max_jing", 5000000);
set("combat_exp", 5000);
set("shen", 0);
set("str", 24);
set("dex", 23);
set("con", 20);
set("per", 30);
set("int", 24);
set("attitude", "friendly");
set("chat_chance", 1);                                            	
set("chat_msg", ({
(: command, "xyxw 新号上线到扬州武庙领取礼物look table；pick gift；chai gift；其他相关通过help查询。" :),       	
(: command, "xyxw 扬州试剑厅有负攻击兵器(风雷剑)拿fly yz;w;n;w;n" :),              	
(: command, "xyxw 钱庄存款上限一百万，上下线金票保留数额50张" :), 
}) );
setup();
carry_object("/clone/cloth/cloth")->wear();
add_money("gold",100);	
}
void die()
{
message_vision("抱歉，我是不会死的。\n",this_object());
return ;
}
