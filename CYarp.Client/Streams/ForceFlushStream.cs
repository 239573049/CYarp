﻿using System;
using System.IO;
using System.Threading;
using System.Threading.Tasks;

namespace CYarp.Client.Streams
{
    /// <summary>
    /// 自动刷新的Stream
    /// </summary>
    sealed class ForceFlushStream : DelegatingStream
    {
        public ForceFlushStream(Stream inner)
            : base(inner)
        {
        }

        public override async ValueTask WriteAsync(ReadOnlyMemory<byte> source, CancellationToken cancellationToken = default)
        {
            await base.WriteAsync(source, cancellationToken);
            await this.FlushAsync(cancellationToken);
        }

        public override ValueTask DisposeAsync()
        {
            return this.Inner.DisposeAsync();
        }

        protected override void Dispose(bool disposing)
        {
            this.Inner.Dispose();
        }
    }
}
