create table users
(
    `id`     int auto_increment primary key,
    `name`   varchar(50) not null,
    `level`  int(2) default 1 not null,
    `bossNo` int(3) default 1 'current number of bosses killed' not null,
    `stats`  text        not null,
    constraint users_id_uindex
        unique (id)
);


create table items
(
    `id`          int auto_increment primary key,
    `name`        varchar(50) not null,
    `value`       int(2) default 1 not null,
    `stat`        enum('physical','magical','health','defense','luck')
        `cost` int (3) default 1 not null,
    `probability` decimal(1, 2) default 1 'odds of showing in shop 0.1 being almost never, 1 very high. increased by luck' not null,
    `passive`     varchar(150),
    constraint items_id_uindex
        unique (id)
);

create table user_items
(
    `userID` int auto_increment primary key,
    `itemID` varchar(50) not null,
    constraint user_item_id_uindex
        unique (id, itemID)
);

create table abilities
(
    `id`          int auto_increment primary key,
    `name`        varchar(50) not null,
    `probability` decimal(1, 2) default 1 'odds of showing 0.1 being almost never, 1 very high. increased by luck' not null,
    `damage`      int(3) default 1 'current number of bosses killed' not null,
    `scale`       decimal(1, 2) default 1 'damage scale with physical or magical' not null,
    `type`        enum('physical','magical') default 1 'the type of damage this scales with' not null,
    constraint users_id_uindex
        unique (id)
);

create table user_abilities
(
    `userID`    int auto_increment primary key,
    `abilityID` varchar(50) not null,
    constraint user_ability_id_uindex
        unique (id, abilityID)
);

create table bosses
(
    `id`    int auto_increment primary key,
    `name`  varchar(50) not null,
    `stats` text        not null,
    constraint bosses_id_uindex
        unique (id)
)