// lingpai.c
inherit ITEM;
void create()
{
        set_name(BLU "云雷令牌" NOR, ({"ling pai", "ling"}));
           if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long", 
                "    "+YEL+"这是一块"+NOR+""+BLU+"令牌"+NOR+""+YEL+",正面刻有一群雷鸟飞翔在云海之上。反面刻着\n"
                "风、云、雷、电四个篆字和一大堆符咒。"+NOR+"\n");
        set("unit", "块");
        set("weight", 10);
        set("no_drop","那么难得的东西你舍得丢弃吗？");
        set("no_sell",1);
        set("no_put",1);
        set("material", "iron");
        }
        setup();
        call_out("dest", 3600);
}
void dest()
{
    object ob=environment(this_object());
    if (ob)
    if (userp(ob)){
            tell_object(ob, HIY "突然空中传来一阵音乐声：你怀里的令牌忽的化作一只金色的\n"+"雷鸟，飞向空中不见了！\n" NOR);
            message("vision",
                HIY "忽听呼地一声，你吓了一跳，定睛一看，\n"
                "只见一只金色的雷鸟飞向空中，一下就不见了！\n" NOR, environment(ob), ob);
    }
    destruct(this_object());
}

int query_autoload() { return 1; }