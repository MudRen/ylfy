inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("��", ({"drunk", "man", "drunk man"}));
        set("long", @TEXT
 
TEXT
        );
        set("gender","����");
        set("age",37);
        set("con",30);
        set("str",30);
        set("combat_exp",100);
        set("attitude","heroism");
        set("chat_chance",10);
        set("chat_msg", ({
        (: do_drink :), }) );
        setup();
    set("water",0);
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("clone/food/jiudai");
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if (!living(this_object()))  return;
    if ((int)this_object()->query("water") >= 400) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop wineskin");
    }
    else {
        command("sigh");
        command("say ��..... ���Ҿ�....");
    }
    return;
}
 
int accept_object(object who, object ob)
{
    object obj,me;
    me=this_object();
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say �յ��Ҳ�Ҫ...");
            return 0;
        }
        else {
            command("smile");
            command("say ��л!");
     if (present("jiudai",me))    set("accept",0);
    else if (!present("book",me)){
            set("accept",1);
            obj=new("clone/book/old_book");
            obj->move(me);
    }
            command("give book to "+who->query("id"));
            return 1;
        }
    }
    else return 0;
}
 
