// /adm/daemons/x_stored.c 储物装备守护程序

inherit F_DBASE;

#define ban_time    2           //限制间隔时间
#define user_pay    5           //存取消耗内力
#define item_min    100          //最小储物数量（及每次扩容额度）
#define item_max    100         //最大储物数量（及每组物品上限）
#define chawu_cmd   "chawu"     //定义查物指令
#define chuwu_cmd   "chuwu"     //定义储物指令
#define quwu_cmd    "quwu"      //定义取物指令
#define augment_cmd "augment"   //定义扩容指令
#define user_mark   "time/use_chuwu"                        //定义用户标记
#define ban_msg     "空间整理中，请稍候再行尝试。\n"        //定义限制讯息

public int do_chawu(object me, object ob);                  //查看存储物品（供储物容器调用）
public int do_chuwu(object me, object ob, string arg);      //进行物品存储（供储物容器调用）
public int do_quwu(object me, object ob, string arg);       //取出存储物品（供储物容器调用）
public int do_augment(object me, object ob);                //进行空间扩容（供储物容器调用）
public int query_min();                                     //查询空间下限（供储物容器调用）
public string cmds_help();                                  //获取指令帮助（供储物容器调用）
public string *able_cmds();                                 //获取指令列表（供储物容器调用）
private int ban_user(object me, object ob);                 //校验用户限制
private int do_put(object me, object obj, object ob);       //执行储物动作
private int do_get(object me, object ob, string arg);       //执行取物动作
private void confirm_aug(string yn, object me, object ob);  //确认空间扩容
private void save_data(object me, object ob);               //保存相应数据
private void msg_info(string msg);                          //发布频道讯息

void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "储物守护");
}

//发布频道讯息
private void msg_info(string msg)
{
    CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

//校验用户限制
private int ban_user(object me, object ob)
{
    int now, old;
    string str;

    if(!ob->query("item_max") || ob->query("item_max") <= 0)
        ob->set("item_max", item_min);  //初始化容器容量

    now = time() & 0xFFFFFFFE;                      //当前时间取值
    old = me->query(user_mark) & 0xFFFFFFFE;        //用户标记取值
    str = ob->query("def_name");                    //容器默认名称
    if(now - old < ban_time)                        //未满限制时间
    {
        tell_object(me, str + ban_msg);             //返回限制讯息
        return 1;
    }

    return 0;
}

//保存相应数据（兼发送相应讯息）
private void save_data(object me, object ob)
{
    int num;
    mapping tmp;
    string msg, str;

    tmp = ob->query_temp("msg");    //临时讯息映射
    if(mapp(tmp) && sizeof(tmp) == 3)
    {

        str = tmp["text"];
        num = tmp["time"];
        msg = replace_string(str, ob->name(), ob->query("def_name"));
        msg = replace_string(msg, me->name(), "你");
        msg = replace_string(msg, "一些", sprintf("%s%s",
                                chinese_number(num), tmp["unit"]));
        tell_object(me, msg);                       //发送用户讯息
        if(num == 1)
            str = replace_string(str, "一些", sprintf("%s%s",
                                chinese_number(num), tmp["unit"]));
        tell_room(environment(me), str, ({ me }));  //发送环境讯息
    }
    if(ob->query_temp("msg"))
        ob->delete_temp("msg");                     //清除临时映射
    me->set(user_mark, time() & 0xFFFFFFFE);        //保存用户标记
    me->save(); //用户存档
    ob->save(); //容器存档
}

//查看存储物品（供储物容器调用）
public int do_chawu(object me, object ob)
{
    mapping obs;
    string msg, str, *key;
    int i, j, x, num, max, use;

    if(ban_user(me, ob))            //校验用户限制
        return 1;

    str = ob->query("def_name");    //容器默认名称
    max = ob->query("item_max");    //容器格数上限
    use = ob->query("item_use");    //容器已用格数
    obs = ob->query("item_list");   //容器物品列表
    msg = sprintf("你的%s：（等级：%-2d 级    容量：%3d / %-3d）\n",
                    str, (max/item_min), use, max);
    msg += sprintf("%s\n", repeat_string("=", 80));
    if(!mapp(obs) || sizeof(obs) <= 0)
    {
        msg += sprintf("%s里面是空的。\n", str);
        tell_object(me, msg);
        return 1;
    }

    key = keys(obs);    //物品列表键值数组
    msg += sprintf("编号%s物品%s单位  数量\n", repeat_string(" ", 4), repeat_string(" ", 50));
    msg += sprintf("%s\n", repeat_string("-", 80));
    for(i = 0, j = 0; i < sizeof(key); i++)
    {
        num = obs[key[i]]["nums"];  //相应物品数量
        j += num;                   //记录物品数量
        if(num > item_max)  //物品数量超过一组
        {
            x = (num / item_max) + 1;   //以物品占用格数进行循环显示
            while(x--)
            {
                if(x > 0)   //循环显示满组的该物品
                    msg += sprintf("%-60s%-4s  %-d\n",
                                    obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                                    obs[key[i]]["unit"], item_max);
                else
                    if((num % item_max) > 0)    //余数大于零，则显示余数
                        msg += sprintf("%-60s%-4s  %-d\n",
                                        obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                                        obs[key[i]]["unit"], (num % item_max));
            }
        }
        else
            msg += sprintf("%-60s%-4s  %-d\n",
                            obs[key[i]]["name"] + "(" + obs[key[i]]["primary_id"] + ")",
                            obs[key[i]]["unit"], obs[key[i]]["nums"]);
    }
    msg += sprintf("%s\n", repeat_string("-", 80));
    msg += sprintf("共有 %d 种物品，合计 %d 件。\n", sizeof(key), j);
    me->set(user_mark, time() & 0xFFFFFFFE);        //保存用户标记
    me->start_more(msg);                            //发送用户讯息
    return 1;
}

//进行物品存储（供储物容器调用）
public int do_chuwu(object me, object ob, string arg)
{
    int i, amount;
    string str, item;
    object obj, obj2, *inv;

    str = ob->query("def_name");    //容器默认名称
    if(!arg)
    {
        tell_object(me, sprintf("你要将什么装入%s？\n", str));
        return 1;
    }

    if(ban_user(me, ob))            //校验用户限制
        return 1;

    //带数量的存储（指令格式：储物 数量 ID）
    if(sscanf(arg, "%d %s", amount, item) == 2)
    {
        if(!objectp(obj = present(item, me)))
        {
            tell_object(me, "你身上没有这样东西。\n");
            return 1;
        }

        if(amount < 1)
        {
            tell_object(me, "物品的数量至少是一个。\n");
            return 1;
        }

        if(amount > item_max)
        {
            tell_object(me, sprintf("每次储物的数量上限是%s件。\n",
                                        chinese_number(item_max)));
            return 1;
        }

        if(obj->query_amount() && !obj->query("armor_prop/armor") //装备
            && !obj->query("weapon_prop/damage") ) //可合并的物件
        {			
            if(amount > obj->query_amount())        //欲存数量超出拥有数量
            {
                tell_object(me, sprintf("你没有那么多的%s。\n", obj->name(1)));
                return 1;
            }
            else
                if(amount == obj->query_amount())   //欲存数量等于拥有数量
                    return do_put(me, obj, ob);
            else                                    //欲存数量小于拥有数量
            {
                obj2 = new(base_name(obj)); //!!!此处有待完善（物品各种数据）
                obj2->set_amount(amount);   //设定存储数量
                if(do_put(me, obj2, ob))    //存储执行成功
                {                           //核减相应数量
                    obj->set_amount(obj->query_amount() - amount);
                    return 1;
                }
                else
                    return 0;
            }
        }
        else    //不可合并物件
        {
            inv = all_inventory(me);    //用户所携物品
            inv = filter_array(inv, (: member_array($(item),
                                $1->parse_command_id_list()) != -1 :));     //筛选ID可相符
            inv = filter_array(inv, (: $1->name(1) == $(obj)->name(1) :));  //筛选名称相符
            if(amount > sizeof(inv))    //欲存数量超出拥有数量
            {
                tell_object(me, sprintf("你没有那么多的%s。\n", obj->name(1)));
                return 1;
            }
            else 
            {   //按照拥有数量进行循环存入
                for(i = 0; i < sizeof(inv); i++)
                {
                    reset_eval_cost();
                    obj2 = inv[i];
                    if(!do_put(me, obj2, ob))   //发生存入失败，循环流程中止
                        break;
                        
                }
                save_data(me, ob);  //保存相应数据
                return 1;
            }
        }
    }

    //不带数量存储（指令格式：储物 ID）
    if(!objectp(obj = present(arg, me)))
    {
        tell_object(me, "你身上没有这样东西。\n");
        return 1;
    }

    do_put(me, obj, ob);    //执行储物动作
    save_data(me, ob);      //保存相应数据
    return 1;
}

//执行储物动作
private int do_put(object me, object obj, object ob)
{
    object *inv;
    string str, arg, *key, slot;
    mapping obs, tmp, msg;
    int num, max, use, xxx, yyy, zzz, i;

    str = ob->query("def_name");    //容器默认名称
    if(obj == ob)   //自身
    {
        tell_object(me, sprintf("试图将%s装入自身会引致不可修复的"
                                "损坏，请小心使用。\n", str));
        return 0;
    }

    if(obj->query("no_put")                 //不可它置
        || obj->query("no_drop")            //不可丢弃
        || obj->query("no_get")             //不可拾取
        || obj->query("no_leave")           //不可离身
        || obj->query("id") == "mailbox")   //个人邮箱
    {
        tell_object(me, sprintf("%s不能离开你。\n", obj->name(1)));
        return 0;
    }

    if(obj->is_character() || obj->query("ride_prop"))  //活人或马匹
    {
        tell_object(me, sprintf("活物不能装入%s。\n", str));
        return 0;
    }

    if(obj->query("money_id")           //金钱
        || obj->query("food_supply")    //食物
        || obj->query("start_fulan")    //会烂
        || obj->query("quest_ob")       //任务
        || obj->query("id") == "corpse" //尸体
		|| obj->query("yao")    //药
		|| obj->query("zhuyao")    //主药
        || obj->query("id") == "pate"//首级
		)  
    {
        tell_object(me, sprintf("%s不是保管箱，不是保鲜柜，垃圾桶,不能装入%s。\n",
                                    str, obj->name(1)));
        return 0;
    }

    if(me->query("neili") < user_pay)   //内力不够支付消耗
    {
        tell_object(me, sprintf("你的内力不够，无法将%s放入%s。\n",
                                    obj->name(1), str));
        return 0;
    }

    if(obj->query("equipped"))          //物件处于装备状态
    {
        tell_object(me, sprintf("请先解除%s的装备状态，否则无法放入%s。\n",
                                    obj->name(1), str));
        return 0;
    }
    if(!obj->query("value") && !obj->value() )          //没有价值的物品
    {
        tell_object(me, sprintf("%s不是保管箱，不是保鲜柜，垃圾桶,不能装入%s。\n",
                                    obj->name(1), str));
        return 0;
    }
	
    inv = all_inventory(obj);
    if(sizeof(inv))                     //物件里面装有物品
    {
        tell_object(me, sprintf("请先清空%s内的物品，否则无法放入%s。\n",
                                    obj->name(1), str));
        return 0;
    }

    if(!mapp(ob->query("item_list")))   //容器无物品列表
        ob->set("item_list", ([]));     //初始化物品列表
    obs = ob->query("item_list");       //载入物品列表
    if(sizeof(obs) > 0)
        key = keys(obs);    //载入物品列表键值数组
    else
        key = ({  });       //物品列表键值数组为空
    xxx = obj->query_amount() ? obj->query_amount() : 1;
    arg = obj->query("id");             //物品ID为键值
    max = ob->query("item_max");        //容器格数上限
    use = ob->query("item_use");        //容器已用格数

    i = sizeof(key);
    if ( !obj->query("armor_prop/armor") //装备
        && !obj->query("weapon_prop/damage") )
    {
        for ( i = 0; i < sizeof(key); i++ )
        {
            if ( arg == obs[key[i]]["primary_id"] )
            {
                slot = key[i];
                break;
            }
        }
    }

    if ( i >= sizeof(key) )  //容器未有该物
    {
        if(use >= max)
        {
            tell_object(me, str + "储物品种已到上限，无法再容纳新品种了。\n");
            return 0;
        }

        for ( i = 0; i < max; i++ )
        {
            slot = sprintf("%d", i);
            if ( member_array(slot, key) == -1 )
            {
                break;
            }
        }

        tmp = ([    slot    : ([     //物品ID为键值
                    "primary_id" : arg,
    /*ID列表*/        "id" : obj->parse_command_id_list(),
    /*物品名称*/    "name" : obj->name(1),
    /*计量单位*/    "unit" : obj->query("unit") ? obj->query("unit") : "件",
    /*详细描述*/    "long" : obj->query("long"),
    /*物品数量*/    "nums" : obj->query_amount() ? obj->query_amount() : 1,
    /*基准文件*/    "file" : base_name(obj),
    /*各种数据*/    "data" : obj->query_entire_dbase(),
               ]), ]);
        obs += tmp;                 //记录物品数据
        ob->set("item_list", obs);  //保存物品列表
        ob->add("item_use", 1);     //增加占用格数
    }
    else    //容器已有该物
    {
        tmp = obs[slot];     //获取原有物品信息
        num = tmp["nums"];  //获取原有物品数量
        if(num + xxx > item_max)    //与原有数量加起来超过一组
        {
            yyy = (num / item_max) + 1;         //原有数量占用格数
            if((num % item_max) == 0)           //若整除后余数为零
                yyy -= 1;                       //占用格数少计一格

            zzz = ((num + xxx) / item_max) + 1; //加入之后占用格数
            if(((num + xxx) % item_max) == 0)   //若整除后余数为零
                zzz -= 1;                       //占用格数少计一格

            if((use - yyy + zzz) > max)   //放入后占用格数会超限，则提示无法放入
            {
                tell_object(me, sprintf("%s的储物容量不够，已经无法再放入"
                                        "%s了。\n", str, obj->name(1)));
                return 0;
            }
        }
        else
            zzz = 0;    //与原有数量相加不超过一组，不会多占格数

        num += xxx;                     //加入物品数量
        obs[slot]["nums"] = num;         //保存物品数量
        ob->set("item_list", obs);      //保存物品列表
        if(zzz > 0)                     //保存占用格数（加入后超过一组的情况）
            ob->set("item_use", use - yyy + zzz);   //减掉原占格数，加入现占格数
    }

//以临时映射记录需发送讯息--------------------------------------------Top------
    msg = ob->query_temp("msg");
    if(!mapp(msg))
        msg = ([]);
    if(!stringp(msg["unit"]))   //计量单位
        msg["unit"] = obj->query("unit") ? obj->query("unit") : "件";
    if(!stringp(msg["text"]))   //文字讯息
        msg["text"] = sprintf("%s将一些%s装入%s。\n",
                                me->name(), obj->name(1), ob->name(1));
    if(!intp(msg["time"]))      //循环次数
        msg["time"] = 0;
    msg["time"] += xxx;
//以临时映射记录需发送讯息--------------------------------------------End------

    ob->set_temp("msg", msg);       //记录讯息映射
    me->add("neili", -user_pay);    //扣除内力消耗
    destruct(obj);                  //销毁原有物品
    return 1;
}

//取出存储物品（供储物容器调用）
public int do_quwu(object me, object ob, string arg)
{
    mapping obs;
    int i, amount, num;
    string str, item, *key, slot;

    str = ob->query("def_name");    //容器默认名称
    if(!arg)
    {
        tell_object(me, sprintf("你要从%s里取出什么？\n", str));
        return 1;
    }

    if(ban_user(me, ob))            //校验用户限制
        return 1;

    obs = ob->query("item_list");   //容器物品列表
    if(!mapp(obs) || sizeof(obs) <= 0)
    {
        tell_object(me, sprintf("%s里面是空的。\n", str));
        return 1;
    }

    key = keys(obs);
    //带数量的取物（指令格式：取物 数量 ID）
    if(sscanf(arg, "%d %s", amount, item) == 2)
    {
        for ( i = 0; i < sizeof(key); i++ )
        {
            if ( item == obs[key[i]]["primary_id"] )
            {
                slot = key[i];
                break;
            }
        }
        if ( i >= sizeof(key) )
        {
            tell_object(me, sprintf("%s里并未储存 %s 这种物品。\n", str, item));
            return 1;
        }

        if(amount < 1)
        {
            tell_object(me, "物品的数量至少是一个。\n");
            return 1;
        }

        if(amount > item_max)
        {
            tell_object(me, sprintf("每次取物的数量上限是%s件。\n",
                                        chinese_number(item_max)));
            return 1;
        }

        num = obs[slot]["nums"];    //物品存有数量
        if(amount > num)
        {
            tell_object(me, sprintf("%s里没有储存那么多的%s。\n",
                                        str, obs[slot]["name"]));
            return 1;
        }
        else
        {   //根据数量循环执行取物
            for(i = 0; i < amount; i++)
            {
                reset_eval_cost();
                if(!do_get(me, ob, item))   //发生取物失败，循环流程中止
                    break;
            }
            save_data(me, ob);  //保存相应数据
            return 1;
        }
    }
    //不带数量取物（指令格式：取物 ID）
    do_get(me, ob, arg);    //执行取物动作
    save_data(me, ob);      //保存相应数据
    return 1;
}

//执行取物动作
private int do_get(object me, object ob, string arg)
{
    object obj;
    mapping obs, tmp, msg;
    string str, *key, slot;
    int i, num, use, xxx, yyy, zzz;

    str = ob->query("def_name");    //容器默认名称
    obs = ob->query("item_list");   //容器物品列表
    key = keys(obs);                //物品列表键值数组

    for ( i = 0; i < sizeof(key); i++ )
    {
        if ( arg == obs[key[i]]["primary_id"] )
        {
            slot = key[i];
            break;
        }
    }

    if ( i >= sizeof(key) )
    {
        tell_object(me, sprintf("%s里并未储存 %s 这种物品。\n", str, arg));
        return 0;
    }

    if(me->query("neili") < user_pay)   //内力不够支付消耗
    {
        tell_object(me, sprintf("你的内力太少，无法从%s里取出物品。\n", str));
        return 0;
    }

    tmp = obs[slot];                         //获取对应数据
    obj = new(tmp["file"]);                 //生成物件副本
    obj->set_name(tmp["name"], tmp["id"]);  //复原名字与ID

    tmp = obs[slot]["data"];                 //获取存档数据
    key = keys(tmp);
    for(i = 0; i < sizeof(key); i++)
    {
        if(key[i] == "id")                  //跳过键值ID
            continue;
        obj->set(key[i], tmp[key[i]]);      //复原各类参数
    }
    obj->move(me);                          //物品移交用户

    xxx = obj->query_amount() ? obj->query_amount() : 1;
    num = obs[slot]["nums"];         //相应物品数量
    use = ob->query("item_use");    //容器已占格数
    if(num == 1)                    //物品仅有一件
    {
        zzz = -1;                   //占用格数减一
        map_delete(obs, slot);       //删除存档数据
    }
    else                            //物品不止一件
    {
        if(num > item_max)          //物品数量超过一组
        {
            yyy = (num / item_max) + 1;         //原有数量占用格数
            if((num % item_max) == 0)           //若整除后余数为零
                yyy -= 1;                       //占用格数少计一格

            zzz = ((num - xxx) / item_max) + 1; //核销之后占用格数
            if(((num - xxx) % item_max) == 0)   //若整除后余数为零
                zzz -= 1;                       //占用格数少计一格

        }
        else                        //物品数量不超一组
            zzz = 0;                //占用格数不变

        num -= 1;                   //核销相应数量
        obs[slot]["nums"] = num;     //保存物品数量
    }

    if(zzz != 0)                                //占用格数有变
        ob->set("item_use", use - yyy + zzz);   //校准占用格数
    ob->set("item_list", obs);                  //保存物品列表

//以临时映射记录需发送讯息--------------------------------------------Top------
    msg = ob->query_temp("msg");
    if(!mapp(msg))
        msg = ([]);
    if(!stringp(msg["unit"]))   //计量单位
        msg["unit"] = obj->query("unit") ? obj->query("unit") : "件";
    if(!stringp(msg["text"]))   //文字讯息
        msg["text"] = sprintf("%s从%s里取出一些%s。\n",
                                me->name(), ob->name(1), obj->name(1));
    if(!intp(msg["time"]))      //循环次数
        msg["time"] = 0;
    msg["time"] += xxx;
//以临时映射记录需发送讯息--------------------------------------------End------

    ob->set_temp("msg", msg);       //记录讯息映射
    me->add("neili", -user_pay);    //扣除内力消耗
    return 1;
}

//进行空间扩容（供储物容器调用）
public int do_augment(object me, object ob)
{
    int now, max, pay;
    string msg, str;

    if(ban_user(me, ob))            //校验用户限制
        return 1;

    str = ob->query("def_name");    //容器默认名称
    now = ob->query("item_max");    //当前等级容量
    if(now >= item_max)             //容量已达上限
    {
        msg = sprintf("\n你的%s已到设计容量上限，无法再提升等级了。\n", str);
        tell_object(me, msg);
        return 1;
    }

    max = now + item_min;                           //下一等级容量
    pay = (max / item_min) * item_min * item_max / 500;   //扩容所需费用
    msg = sprintf("\n你的%s当前等级为%s级（容量%s格），提升到%s级（容"
                  "量%s格）需要花费%s万两黄金，是否确认(Yes/No)？\n",
                    str, chinese_number(now/item_min),
                    chinese_number(now), chinese_number(max/item_min),
                    chinese_number(max), chinese_number(pay));
    msg = sort_string(msg, 64, 0);
    tell_object(me, msg);               //用户提示讯息
    input_to("confirm_aug", me, ob);    //确认空间扩容
    return 1;
}

//确认空间扩容
private void confirm_aug(string yn, object me, object ob)
{
    int now, max, pay;
    string msg, str;

    str = ob->query("def_name");    //容器默认名称
    if(yn[0] != 'y' && yn[0] != 'Y')
    {
        tell_object(me, sprintf("\n你放弃了对%s进行升级。\n", str));
        return;
    }

    now = ob->query("item_max");                    //当前等级容量
    max = now + item_min;                           //下一等级容量
    pay = (max / item_min) * item_min * item_max/500;   //扩容所需费用
    if(me->query("more_money") < pay)                //存款不够支付
    {
        msg = sprintf("\n你的钱庄存款不够支付%s的升级费用%s万两黄金，"
                      "请存够钱再来。\n", str, chinese_number(pay));
        tell_object(me, msg);
        return;
    }

    me->add("more_money", -pay); //支付扩容费用
    ob->set("item_max", max);   //保存新的容量
    save_data(me, ob);          //保存相应数据

    msg = sprintf("\n你花费%s万两黄金将%s提升到了%s级（容量%s格）。\n",
                    chinese_number(pay), str,
                    chinese_number(max/item_min),
                    chinese_number(max));
    tell_object(me, msg);       //用户提示讯息

    msg = replace_string(msg, "\n", "");
    msg = replace_string(msg, "你", "据说某人");
    msg_info(msg);              //公众频道讯息
    return;
}

//指令对应内容
static mapping item_cmds = ([
    augment_cmd : sprintf("等级提升：%s （最高%s级）",
                            augment_cmd, chinese_number(item_max/item_min)),
    chawu_cmd   : sprintf("查看内容：%s", chawu_cmd),
    chuwu_cmd   : sprintf("储存物品：%s [数量] <物品ID>", chuwu_cmd),
    quwu_cmd    : sprintf("取出物品： %s [数量] <物品ID>", quwu_cmd),
]);

//获取指令帮助（供储物容器调用）
public string cmds_help()
{
    int i;
    string msg, *key;

    msg = sprintf("\n『%s』玄奇事物研发公司制造，广告位招租中。\n", MUD_NAME);
    key = sort_array(keys(item_cmds), 1);
    for(i = 0; i < sizeof(key); i++)
        msg += sprintf("%s\n", item_cmds[key[i]]);
    msg += "\n";
    return msg;
}

//附加指令列表（供储物容器调用）
public string *able_cmds()
{
    return sort_array(keys(item_cmds), 1);
}

//查询空间下限（供储物容器调用）
public int query_min()
{
    return item_min;
}
