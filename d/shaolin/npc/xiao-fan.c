// seller.c
inherit NPC;
inherit F_VENDOR;
void create()
{
    set_name("С��", ({ "xiao fan", "seller", "fan" }) );
    set("gender", "����" );
    set("age", 32);
    set("long",
        "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
    set("shen_type", 1);
    set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
    set("attitude", "peaceful");
    set("vendor_goods", ({
        "/d/shaolin/obj/map",
        "/d/shaolin/obj/guide",
        "/clone/food/bo",
        "/clone/cloth/stick",
        "/clone/cloth/shoes",
        "/clone/food/bottle",
    }) );
    setup();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
int do_buy(string arg)
{
    int amount,once;
    string items,targ;
        if(sscanf(arg, "%d %s %d from %s",amount,items,once, targ)!=4 )
            if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
            if(sscanf(arg, "%s %d from %s", items,once,targ)!=3 )
        if( sscanf(arg, "%d %s %d",amount,items,once)!=3 )
                if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
            if( sscanf(arg, "%s %d",items,once)!=2 )
                items=arg;
     if (items=="suger" && is_vendor_good(items,once) )
       {
         if (amount>1 ) { command("say sorry,��ֻ��һ����");  return 1; }
              if ( ::do_buy(arg) ) {
               set("vendor_goods",({
        "/d/shaolin/obj/map",
        "/d/shaolin/obj/guide",
        "/clone/cloth/stick",
        "/clone/cloth/shoes",
        "/clone/food/bottle",
         }));
         return 1;
        }
    }
    else return ::do_buy(arg);
}
